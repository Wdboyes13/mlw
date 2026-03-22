/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Runtime (VM) Class Definition (vm_class.hpp) */

#pragma once

#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/InitLLVM.h>
#include <csignal>
#include <memory>
#include <system_error>
#include "llvm/Support/Signals.h"

class Logger {
    std::string full_log;
    bool debug;
    llvm::raw_fd_ostream file;
    std::error_code ec;
    static Logger* current_logger;

    void handle_crash(int code) {
        llvm::errs() << "ERROR OCCURRED - FULL LOG @ __mlw_vm.log\n";
        llvm::errs() << "If this is a bug, report it @ willdev2025@outlook.com "
                        "along with the log contents\n";
        llvm::errs() << "VM ABORTING\n";

        file << "\n=== CRASH SIGNAL " << strsignal(code) << " ===\n";
        file << "=== STACK TRACE ===\n";
        llvm::sys::PrintStackTrace(file);
        file << "\n=== PROGRAM LOG ===\n";
        file << full_log;
        file.flush();
        std::_Exit(1);
    }

    static void signal_handler(int signal) {
        if (current_logger) {
            current_logger->handle_crash(signal);
        }

        std::_Exit(1);
    }

  public:
    Logger(bool debug)
        : debug(debug), file("__mlw_vm.log", ec, llvm::sys::fs::OF_Text) {
        llvm::sys::DisableSystemDialogsOnCrash();
        current_logger = this;
        std::signal(SIGABRT, signal_handler);
        std::signal(SIGSEGV, signal_handler);
        std::signal(SIGILL, signal_handler);
        std::signal(SIGFPE, signal_handler);
    }

    void log(std::string message) {
        full_log.append(message);
        if (debug) {
            llvm::errs() << message;
        }
    }

    void log(int message) {
        full_log.append(std::to_string(message));
        if (debug) {
            llvm::errs() << message;
        }
    }

    template<typename... T>
    Logger& operator<<(T... str) {
        log(str...);
        return *this;
    }

    void abort() { handle_crash(SIGABRT); }
};

inline Logger* Logger::current_logger = nullptr;

class MLWVM {
  private:
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::orc::LLJIT> jit;
    llvm::LLVMContext& context;
    std::unique_ptr<llvm::InitLLVM> init_llvm;

    int num_implibs;
    std::vector<std::string> implibs;
    std::string script_path;

  public:
    Logger log;
    std::string locate_lib(const std::string& basename);
    MLWVM(std::unique_ptr<llvm::Module> mod,
          llvm::LLVMContext& ctx,
          int argc,
          char** argv,
          std::string script_pth,
          bool debug);
    void find_implibs();
    void finalize();
    llvm::GenericValue
    run_function(const std::string& functionName,
                 const std::vector<llvm::GenericValue>& args = {});
};
