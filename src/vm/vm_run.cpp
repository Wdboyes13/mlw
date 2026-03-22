/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Runtime (VM) Function Executor (vm_run.cpp) */

#include "vm_class.hpp"

llvm::GenericValue
MLWVM::run_function(const std::string& functionName,
                    const std::vector<llvm::GenericValue>& args) {
    if (!jit) {
        log << "JIT not initialized. Call finalize() first.\n";
        return llvm::GenericValue();
    }

    // Lookup the function
    auto sym = jit->lookup(functionName);
    if (!sym) {
        log << "Function '" << functionName
            << "' not found: " << llvm::toString(sym.takeError()) << "\n";
        return llvm::GenericValue();
    }

    log << "Executing function: " << functionName << "\n";

    // Cast to function pointer and call
    using MainFunc = int (*)(void);
    auto func_ptr = sym.get().toPtr<MainFunc>();
    int result = func_ptr();

    // Convert to GenericValue
    llvm::GenericValue gv;
    gv.IntVal = llvm::APInt(32, result);
    return gv;
}
