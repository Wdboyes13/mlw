/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13 
   This code is part of the MLW Project 
   Runtime (VM) Class Definition (vm_class.hpp) */

#pragma once

#include <memory>
#include <llvm/IR/Module.h>
#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/ExecutionEngine/GenericValue.h>

class MLWVM {
private:
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::orc::LLJIT> jit;
    llvm::LLVMContext& context;
    std::unique_ptr<llvm::InitLLVM> initLLVM;

    int num_implibs;
    std::vector<std::string> implibs;
    std::string script_path;

public:
    std::string locate_lib(const std::string &basename, std::string script_basename);
    MLWVM(std::unique_ptr<llvm::Module> mod, llvm::LLVMContext& ctx, int argc, char** argv, std::string script_pth);
    void findImplibs();
    void finalize();
    llvm::GenericValue runFunction(const std::string& functionName,
                                  const std::vector<llvm::GenericValue>& args = {});
};