/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13 
   This code is part of the MLW Project 
   Runtime (VM) Finalization (vm_finalize.cpp) */

#include "vm_class.hpp"
#include <filesystem>

void MLWVM::finalize() {
    // Create LLJIT instance
    auto jitResult = llvm::orc::LLJITBuilder().create();
    if (!jitResult) {
        llvm::errs() << "Failed to create LLJIT: "
                    << llvm::toString(jitResult.takeError()) << "\n";
        std::abort();
    }

    jit = std::move(*jitResult);

    // Load system libraries first
    llvm::sys::DynamicLibrary::LoadLibraryPermanently(nullptr);

    // Load your import libraries
    for (const auto& libName : implibs) {
        std::string fullLibName = std::filesystem::absolute(locate_lib(libName, script_path));

        llvm::errs() << "Loading library: " << fullLibName << "\n";

        std::string errorMsg;
        if (!llvm::sys::DynamicLibrary::LoadLibraryPermanently(fullLibName.c_str(), &errorMsg)) {
            llvm::errs() << "Successfully loaded: " << fullLibName << "\n";
        } else {
            llvm::errs() << "Warning: Failed to load " << fullLibName << ": " << errorMsg << "\n";

            // Try without prefix/suffix
            if (!llvm::sys::DynamicLibrary::LoadLibraryPermanently(libName.c_str(), &errorMsg)) {
                llvm::errs() << "Successfully loaded: " << libName << " (raw name)\n";
            } else {
                llvm::errs() << "Error: Could not load library in any form: " << libName << "\n";
            }
        }
    }

    // Add the module to JIT
    llvm::orc::ThreadSafeModule tsm(std::move(module), std::make_unique<llvm::LLVMContext>());
    if (auto err = jit->addIRModule(std::move(tsm))) {
        llvm::errs() << "Failed to add IR module: " << llvm::toString(std::move(err)) << "\n";
        std::abort();
    }

    llvm::errs() << "JIT engine finalized successfully with " << implibs.size() << " libraries loaded\n";
}