/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Parse tree generator header (gen_tree.hpp) */

#pragma once

#include <MLWLexer.h>
#include <MLWParser.h>
#include <string>

struct ParseResources {
    // We use unique_ptr to manage the dynamic allocation and ensure proper
    // cleanup.
    std::unique_ptr<std::ifstream> stream;
    std::unique_ptr<antlr4::ANTLRInputStream> input;
    std::unique_ptr<MLWLexer> lexer;
    std::unique_ptr<antlr4::CommonTokenStream> tokens;
    std::unique_ptr<MLWParser> parser;
    MLWParser::ProgramContext* tree = nullptr; // Raw pointer to the tree (owned by the parser)
};

// Update generate_tree to return this new structure
std::unique_ptr<ParseResources> generate_tree(const std::string& filename);
