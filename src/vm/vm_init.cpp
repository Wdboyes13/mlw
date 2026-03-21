/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Runtime (VM) Initialization (vm_init.cpp) */

#include <config.h>
#include <llvm/Support/TargetSelect.h>

#include "vm_class.hpp"

#if defined(MLW_TARGET_AArch64)
#    define InitializeAll()                \
        LLVMInitializeAArch64TargetInfo(); \
        LLVMInitializeAArch64Target();     \
        LLVMInitializeAArch64TargetMC();   \
        LLVMInitializeAArch64AsmPrinter(); \
        LLVMInitializeAArch64AsmParser()
#elif defined(MLW_TARGET_X86)
#    define InitializeAll()            \
        LLVMInitializeX86TargetInfo(); \
        LLVMInitializeX86Target();     \
        LLVMInitializeX86TargetMC();   \
        LLVMInitializeX86AsmPrinter(); \
        LLVMInitializeX86AsmParser()
#elif defined(MLW_TARGET_ARM)
#    define InitializeAll()            \
        LLVMInitializeARMTargetInfo(); \
        LLVMInitializeARMTarget();     \
        LLVMInitializeARMTargetMC();   \
        LLVMInitializeARMAsmPrinter(); \
        LLVMInitializeARMAsmParser()
#elif defined(MLW_TARGET_PowerPC)
#    define InitializeAll()                \
        LLVMInitializePowerPCTargetInfo(); \
        LLVMInitializePowerPCTarget();     \
        LLVMInitializePowerPCTargetMC();   \
        LLVMInitializePowerPCAsmPrinter(); \
        LLVMInitializePowerPCAsmParser()
#elif defined(MLW_TARGET_RISCV)
#    define InitializeAll()              \
        LLVMInitializeRISCVTargetInfo(); \
        LLVMInitializeRISCVTarget();     \
        LLVMInitializeRISCVTargetMC();   \
        LLVMInitializeRISCVAsmPrinter(); \
        LLVMInitializeRISCVAsmParser()
#elif defined(MLW_TARGET_Mips)
#    define InitializeAll()             \
        LLVMInitializeMipsTargetInfo(); \
        LLVMInitializeMipsTarget();     \
        LLVMInitializeMipsTargetMC();   \
        LLVMInitializeMipsAsmPrinter(); \
        LLVMInitializeMipsAsmParser()
#elif defined(MLW_TARGET_Sparc)
#    define InitializeAll()              \
        LLVMInitializeSparcTargetInfo(); \
        LLVMInitializeSparcTarget();     \
        LLVMInitializeSparcTargetMC();   \
        LLVMInitializeSparcAsmPrinter(); \
        LLVMInitializeSparcAsmParser()
#elif defined(MLW_TARGET_SystemZ)
#    define InitializeAll()                \
        LLVMInitializeSystemZTargetInfo(); \
        LLVMInitializeSystemZTarget();     \
        LLVMInitializeSystemZTargetMC();   \
        LLVMInitializeSystemZAsmPrinter(); \
        LLVMInitializeSystemZAsmParser()
#endif

MLWVM::MLWVM(std::unique_ptr<llvm::Module> mod, llvm::LLVMContext& ctx,
             int argc, char** argv, std::string script_pth, bool debug)
    : module(std::move(mod)), context(ctx), script_path(script_pth),
      log(debug) {
    // Initialize LLVM targets
    InitializeAll();

    // JIT-specific initialization
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    initLLVM = std::make_unique<llvm::InitLLVM>(argc, argv);
    findImplibs();
}
