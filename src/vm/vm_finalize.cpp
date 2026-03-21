/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Runtime (VM) Finalization (vm_finalize.cpp) */

#include <llvm/Support/FileSystem.h>
#include "vm_class.hpp"

void MLWVM::finalize() {
    // Create LLJIT instance
    auto jitResult = llvm::orc::LLJITBuilder().create();
    if (!jitResult) {
        log << "Failed to create LLJIT: "
            << llvm::toString(jitResult.takeError()) << "\n";
        log.abort();
    }

    jit = std::move(*jitResult);

    // Load system libraries first
    llvm::sys::DynamicLibrary::LoadLibraryPermanently(nullptr);

    // Load your import libraries
    for (const auto& libName : implibs) {
        std::string fullLibName = locate_lib(libName);

        log << "Loading library: " << fullLibName << "\n";

        std::string errorMsg;
        if (!llvm::sys::DynamicLibrary::LoadLibraryPermanently(
                fullLibName.c_str(), &errorMsg)) {
            log << "Successfully loaded: " << fullLibName << "\n";
        } else {
            log << "Warning: Failed to load " << fullLibName << ": " << errorMsg
                << "\n";

            // Try without prefix/suffix
            if (!llvm::sys::DynamicLibrary::LoadLibraryPermanently(
                    libName.c_str(), &errorMsg)) {
                log << "Successfully loaded: " << libName << " (raw name)\n";
            } else {
                log << "Error: Could not load library in any form: " << libName
                    << "\n";
                log.abort();
            }
        }
    }

    // Add the module to JIT
    llvm::orc::ThreadSafeModule tsm(std::move(module),
                                    std::make_unique<llvm::LLVMContext>());
    if (auto err = jit->addIRModule(std::move(tsm))) {
        log << "Failed to add IR module: " << llvm::toString(std::move(err))
            << "\n";
        log.abort();
    }

    log << "JIT engine finalized successfully with " << implibs.size()
        << " libraries loaded\n";
}
