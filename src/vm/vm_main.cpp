/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Runtime (VM) Entry Point (vm_main.cpp) */

#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/Program.h>
#include <filesystem>
#include "vm_class.hpp"

namespace fs = std::filesystem;

llvm::cl::opt<std::string> file(
    llvm::cl::Positional,
    llvm::cl::desc("File to run"),
    llvm::cl::Required);

llvm::cl::opt<bool> debug(
    "debug",
    llvm::cl::desc("Enable Debug Output"),
    llvm::cl::init(false));

#define LLVM_BC_MAG1 0x42
#define LLVM_BC_MAG2 0x43
#define LLVM_BC_MAG3 0xc0
#define LLVM_BC_MAG4 0xde

int main(int argc, char** argv);

std::string locate_compiler(const char* av0) {
    auto exe_path = llvm::sys::findProgramByName("mlwc");
    if (!exe_path) {
        auto this_exe =
            llvm::sys::fs::getMainExecutable(av0, (void*)(intptr_t)main);
        if (this_exe.empty()) {
            return "";
        }

        auto exe_dir = std::filesystem::path(this_exe).parent_path();

#ifndef _WIN32
        auto possible_path = exe_dir / "mlwc";
#else
        auto possible_ath = exeDir / "mlwc.exe";
#endif

        if (llvm::sys::fs::exists(possible_path.c_str())) {
            return possible_path;
        } else {
            llvm::errs() << "Not a bitcode file and could not find mlwc\n";
            return "";
        }
    } else {
        return exe_path.get();
    }
}

int main(int argc, char** argv) {
    llvm::cl::ParseCommandLineOptions(argc, argv, "mlw - MLW VM");

    llvm::setBugReportMsg("Please submit this error to willdev2025@outlook.com "
                          "along with the contents of __mlw_vm.log\n");

    auto sfile = fs::path();

    auto filebuffer = llvm::MemoryBuffer::getFile(sfile.c_str());
    if (!filebuffer) {
        llvm::errs() << "Failed to read file '" << sfile << "'\n";
        return 1;
    }

    auto is_bc_file = [](const std::vector<unsigned char>& bytes) {
        return (bytes[0] == LLVM_BC_MAG1 && bytes[1] == LLVM_BC_MAG2 &&
                bytes[2] == LLVM_BC_MAG3 && bytes[3] == LLVM_BC_MAG4);
    };

    auto bytes_buf = filebuffer.get()->getMemBufferRef().getBuffer().bytes();
    std::vector<unsigned char> bytes(bytes_buf.begin(), bytes_buf.end());
    if (!bytes.empty() && bytes.size() >= 4) {
        // if this isnt a bitcode file, run the compiler
        if (!is_bc_file(bytes)) {
            auto exe_path = locate_compiler(argv[0]);
            if (exe_path.empty()) {
                llvm::errs() << "Not a bitcode file and could not locate mlwc";
                return 1;
            }
            llvm::SmallVector<llvm::StringRef> args = {exe_path, sfile.c_str()};
            if (debug) {
                args.push_back("--debug");
            }
            std::string err_msg;
            int ret = llvm::sys::ExecuteAndWait(exe_path.c_str(), args, std::nullopt, {}, 0, 0, &err_msg);

            if (ret != 0) {
                llvm::errs() << "Not a bitcode file and mlwc failed\n";
                return 1;
            } else {
                sfile = sfile.replace_extension(".mlwbc");
                filebuffer = llvm::MemoryBuffer::getFile(sfile.c_str());
                if (!filebuffer) {
                    llvm::errs() << "Failed to read file '" << sfile << "'\n";
                    return 1;
                }
            }
        }
    }

    auto context = std::make_unique<llvm::LLVMContext>();
    auto module_result =
        llvm::parseBitcodeFile(filebuffer.get()->getMemBufferRef(), *context);

    if (!module_result) {
        llvm::errs() << "Failed to parse bitcode file: "
                     << llvm::toString(module_result.takeError()) << "\n";
        return 1;
    }

    auto vm = new MLWVM(
        std::move(*module_result),
        *context,
        argc,
        argv,
        argv[1],
        debug);
    vm->finalize();
    vm->run_function("main");
}
