/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13 
   This code is part of the MLW Project 
   Runtime (VM) Entry Point (vm_main.cpp) */

#include "vm_class.hpp"
#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Support/MemoryBuffer.h>
#include <filesystem>

int main(int argc, char** argv) {
    if (argc < 2) {
        llvm::errs() << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    auto filebuffer = llvm::MemoryBuffer::getFile(argv[1]);
    if (!filebuffer) {
        llvm::errs() << "Failed to read file '" << argv[1] << "'\n";
        return 1;
    }

    auto context = std::make_unique<llvm::LLVMContext>();
    auto moduleResult = llvm::parseBitcodeFile(filebuffer.get()->getMemBufferRef(), *context);

    if (!moduleResult) {
        llvm::errs() << "Failed to parse bitcode file: " << llvm::toString(moduleResult.takeError()) << "\n";
        return 1;
    }

    std::filesystem::path script = argv[1];
    std::string script_path;
    if (script.has_parent_path()) script_path = script.parent_path().string() + "/";
    else script_path = "./";

    auto vm = new MLWVM(std::move(*moduleResult), *context, argc, argv, script_path);
    vm->finalize();
    vm->runFunction("main");
}