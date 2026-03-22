/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Compiler Driver (driver.cpp) */

#include <llvm/Support/CommandLine.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/Program.h>
#include <llvm/Support/ToolOutputFile.h>

#include <filesystem>

namespace fs = std::filesystem;

int gen_llvm_main(bool debug, std::string file, std::string og_file);

static llvm::cl::opt<bool> debug(
    "debug",
    llvm::cl::desc("Enable debug output"),
    llvm::cl::init(false));
static llvm::cl::opt<bool> no_pp(
    "npp",
    llvm::cl::desc("Disable preprocessor"),
    llvm::cl::init(false));

static llvm::cl::opt<std::string> pp_path(
    "pp-path",
    llvm::cl::desc("Path to preprocessor"),
    llvm::cl::init(""));

static llvm::cl::opt<std::string> file_path(
    llvm::cl::Positional,
    llvm::cl::desc("<SOURCE_FILE>"),
    llvm::cl::Required);

int main(int argc, char* argv[]);
std::string locate_preprocessor(const char* av0) {
    if (!pp_path.empty() && fs::exists(pp_path.getValue())) {
        return pp_path.getValue();
    }

    auto exepath = llvm::sys::findProgramByName("mlwpp");
    if (!exepath) {
        auto texe = llvm::sys::fs::getMainExecutable(av0, (void*)(intptr_t)main);
        if (texe.empty()) {
            return "";
        }

        auto exedir = fs::path(texe).parent_path();
#ifndef _WIN32
        auto ppath = exedir / "mlwpp";
#else
        auto ppath = exedir / "mlwpp.exe";
#endif
        if (fs::exists(ppath)) {
            return ppath;
        } else {
            llvm::errs() << "Could not locate preprocessor";
            return "";
        }
    } else {
        return exepath.get();
    }
}

std::optional<std::string> run_preprocessor(const char* av0) {
    auto pp = locate_preprocessor(av0);
    if (pp.empty()) {
        return std::nullopt;
    }

    llvm::SmallVector<llvm::StringRef> args = {pp, file_path};
    std::string err;

    llvm::SmallString<128> tmp_path;
    llvm::sys::fs::createTemporaryFile("mlwpp-output", "tmp", tmp_path);

    args.push_back("--debug");

    std::optional<llvm::StringRef> redirects[] = {
        std::nullopt,
        tmp_path,
        std::nullopt};

    int ret = llvm::sys::ExecuteAndWait(pp, args, std::nullopt, redirects, 0, 0, &err);

    if (ret == 0) {
        return tmp_path.str().str();
    } else {
        return std::nullopt;
    }
}

int main(int argc, char* argv[]) {
    llvm::cl::ParseCommandLineOptions(argc, argv, "mlwc - MLW Compiler\n");

    auto file = file_path.getValue();

    if (!no_pp) {
        auto ppret = run_preprocessor(argv[0]);
        if (!ppret) {
            llvm::errs() << "Preprocessing failed\n";
            return 1;
        } else {
            file = ppret.value();
        }
    }

    return gen_llvm_main(debug, file, file_path);
}
