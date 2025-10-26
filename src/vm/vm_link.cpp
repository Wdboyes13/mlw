/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13 
   This code is part of the MLW Project 
   Runtime (VM) Import Library Resolution (vm_link.cpp) */

#include "vm_class.hpp"
#include <llvm/Support/Path.h>
#include <llvm/Support/FileSystem.h>

std::string MLWVM::locate_lib(const std::string &basename) {
    llvm::SmallString<128> cwd;
    if (auto ec = llvm::sys::fs::current_path(cwd)) {
        log << "Error getting current path: " << ec.message() << "\n";
        log.abort();
    }

    llvm::SmallString<128> temp_path = cwd;
    llvm::sys::path::append(temp_path, basename);
    llvm::sys::fs::make_absolute(temp_path, temp_path);
    llvm::SmallString<128> parent_path = llvm::sys::path::parent_path(temp_path);

    if (!parent_path.empty() && !llvm::sys::path::is_separator(parent_path.back())) {
        parent_path += llvm::sys::path::get_separator();
    }

    auto script_basename = parent_path.str().str();
    
    std::vector<std::string> search_paths = {
        script_basename, 
        "/usr/local/lib/mlw/",
        "./lib/mlw/", 
        "../lib/mlw/",
        "./"
    };

    for (const auto& search_path : search_paths) {
        llvm::SmallString<256> full_path;
        full_path = search_path;
        llvm::sys::path::append(full_path, basename);
        llvm::SmallString<256> abs_path;
        if (auto ec = llvm::sys::fs::make_absolute(full_path)) {
            log << "Path error: " << ec.message() << " for " << full_path.c_str() << "\n";
            continue;
        }
        llvm::sys::path::remove_dots(full_path, true);

        log << "Checking " << full_path.c_str() << "\n";
        if (llvm::sys::fs::exists(full_path)) {
            return full_path.c_str();
        } else {
            log << "Not found at: " << full_path.c_str() << "\n";
        }
    }
    
    log << "No match found for library\n";
    log.abort();
}

void MLWVM::findImplibs() {
    auto globcount = module->getNamedGlobal("__vm_implibs_count");
    if (!globcount) {
        log << "Couldn't find import library count\n";
        log.abort();
    }
    auto initcount = globcount->getInitializer();
    if (auto* constint = llvm::dyn_cast<llvm::ConstantInt>(initcount)) {
        num_implibs = constint->getZExtValue();
    }

    for (int i = 0; i < num_implibs; i++) {
        auto implib_var = module->getNamedGlobal("__vm_implibs." + std::to_string(i));
        if (!implib_var) {
            log << "Import Library Count Variable (__vm_implibs_count) contains incorrect value\n";
            log.abort();
        }

        auto implib_initializer = implib_var->getInitializer();
        if (auto* constint = llvm::dyn_cast<llvm::ConstantDataArray>(implib_initializer)) {
            implibs.push_back(constint->getAsString().str());
        }
    }

    log << "Found " << num_implibs << " import libraries:\n";
    for (const auto& lib : implibs) {
        log << "  - " << lib << "\n";
    }
}