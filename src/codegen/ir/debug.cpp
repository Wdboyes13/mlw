/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13 
   This code is part of the MLW Project 
   Debug printer (debug.cpp) */

#include "../gen_llvm.hpp"
#include "ParserRuleContext.h"
#include "tree/TerminalNode.h"

void LLVMGen::enterEveryRule(antlr4::ParserRuleContext *ctx) {
    if (debug) llvm::outs() << "ENTER RULE: " << debug_parse_rsrsc->parser->getRuleNames().at(ctx->getRuleIndex()) << "\n";
}

void LLVMGen::visitTerminal(antlr4::tree::TerminalNode* node) {
    if (debug) llvm::outs() << "VISIT TERMINAL: " << node->getSymbol() << "\n";
}