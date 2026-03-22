/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Runtime (VM) Finalization (vm_finalize.cpp) */

#include <llvm/Support/FileSystem.h>
#include "vm_class.hpp"

void MLWVM::finalize() {
    // Create LLJIT instance
    auto jit_result = llvm::orc::LLJITBuilder().create();
    if (!jit_result) {
        log << "Failed to create LLJIT: "
            << llvm::toString(jit_result.takeError()) << "\n";
        log.abort();
    }

    jit = std::move(*jit_result);

    // Load system libraries first
    llvm::sys::DynamicLibrary::LoadLibraryPermanently(nullptr);

    // Load your import libraries
    for (const auto& lib_name : implibs) {
        std::string full_lib_name = locate_lib(lib_name);

        log << "Loading library: " << full_lib_name << "\n";

        std::string error_msg;
        if (!llvm::sys::DynamicLibrary::LoadLibraryPermanently(
                full_lib_name.c_str(),
                &error_msg)) {
            log << "Successfully loaded: " << full_lib_name << "\n";
        } else {
            log << "Warning: Failed to load " << full_lib_name << ": "
                << error_msg << "\n";

            // Try without prefix/suffix
            if (!llvm::sys::DynamicLibrary::LoadLibraryPermanently(
                    lib_name.c_str(),
                    &error_msg)) {
                log << "Successfully loaded: " << lib_name << " (raw name)\n";
            } else {
                log << "Error: Could not load library in any form: " << lib_name
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
