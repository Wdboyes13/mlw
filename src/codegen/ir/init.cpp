/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Compiler Initialization & Deinitialization (init.cpp) */

#include "../gen_llvm.hpp"

#include <MLWLexer.h>
#include <MLWParser.h>

#include <llvm/IR/Verifier.h>

using namespace antlr4;

LLVMGen::LLVMGen(llvm::LLVMContext* ctx, ParseResources* rsrsc, bool _debug)
    : ctx(ctx), builder(*ctx), debug_parse_rsrsc(rsrsc), debug(_debug) {}

void LLVMGen::enterProgram(MLWParser::ProgramContext* ctx) {
    module = std::make_unique<llvm::Module>("program", *this->ctx);
}

void LLVMGen::exitProgram(MLWParser::ProgramContext* ctx) {
    auto val = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*this->ctx), implibs_idx);
    auto var = new llvm::GlobalVariable(
        *module,
        val->getType(),
        true,
        llvm::GlobalVariable::ExternalLinkage,
        val,
        "__vm_implibs_count");

    if (llvm::verifyModule(*module, &llvm::errs())) {
        llvm::errs() << "Module verification failed\n";
    }
}
