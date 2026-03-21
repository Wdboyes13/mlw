/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Runtime (VM) Entry Point (vm_main.cpp) */

#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Support/MemoryBuffer.h>
#include <filesystem>
#include "llvm/Support/PrettyStackTrace.h"
#include "vm_class.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        llvm::errs() << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    bool debug = false;

    if (argc > 2) {
        for (int i = 2; i < argc; i++) {
            if (std::string(argv[i]) == "-d" ||
                std::string(argv[i]) == "--debug")
                debug = true;
        }
    }

    llvm::setBugReportMsg("Please submit this error to willdev2025@outlook.com "
                          "along with the contents of __mlw_vm.log\n");

    auto filebuffer = llvm::MemoryBuffer::getFile(argv[1]);
    if (!filebuffer) {
        llvm::errs() << "Failed to read file '" << argv[1] << "'\n";
        return 1;
    }

    auto context = std::make_unique<llvm::LLVMContext>();
    auto moduleResult =
        llvm::parseBitcodeFile(filebuffer.get()->getMemBufferRef(), *context);

    if (!moduleResult) {
        llvm::errs() << "Failed to parse bitcode file: "
                     << llvm::toString(moduleResult.takeError()) << "\n";
        return 1;
    }

    std::filesystem::path script = argv[1];

    auto vm = new MLWVM(std::move(*moduleResult), *context, argc, argv, script,
                        debug);
    vm->finalize();
    vm->runFunction("main");
}
