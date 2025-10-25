#pragma once

#include <string>
#include <MLWParser.h>
#include <MLWLexer.h>

struct ParseResources {
    // We use unique_ptr to manage the dynamic allocation and ensure proper cleanup.
    std::unique_ptr<std::ifstream> stream;
    std::unique_ptr<antlr4::ANTLRInputStream> input;
    std::unique_ptr<MLWLexer> lexer;
    std::unique_ptr<antlr4::CommonTokenStream> tokens;
    std::unique_ptr<MLWParser> parser;
    MLWParser::ProgramContext* tree = nullptr; // Raw pointer to the tree (owned by the parser)
};

// Update generate_tree to return this new structure
std::unique_ptr<ParseResources> generate_tree(const std::string& filename);