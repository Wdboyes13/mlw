/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Parse tree generator (gen_tree.cpp) */

#include <MLWLexer.h>
#include <MLWParser.h>
#include "ANTLRInputStream.h"

#include <fstream>
#include <string>

#include "gen_tree.hpp"

using namespace antlr4;

std::unique_ptr<ParseResources> generate_tree(const std::string& filename) {
    auto res = std::make_unique<ParseResources>();
    res->stream = std::make_unique<std::ifstream>();
    res->stream->open(filename);
    if (!res->stream->is_open()) {
        return nullptr;
    }

    res->input = std::make_unique<ANTLRInputStream>(*res->stream);
    res->lexer = std::make_unique<MLWLexer>(res->input.get());
    res->tokens = std::make_unique<CommonTokenStream>(res->lexer.get());
    res->parser = std::make_unique<MLWParser>(res->tokens.get());

    res->tree = res->parser->program();
    return res;
}
