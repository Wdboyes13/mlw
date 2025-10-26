/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13 
   This code is part of the MLW Project 
   Runtime (VM) Import Library Resolution (vm_link.cpp) */

#include "vm_class.hpp"

std::string MLWVM::locate_lib(const std::string &basename, std::string script_basename) {
    std::vector<std::string> search_paths = {
        script_basename, 
        "/usr/local/lib/mlw/",
        "./lib/mlw/", 
        "../lib/mlw/",
        "./"  // Add current directory as fallback
    };

    for (const auto& search_path : search_paths) {
        std::string full_path = search_path + basename;
        llvm::errs() << "Checking " << full_path << "\n";
            
        FILE* f = fopen(full_path.c_str(), "r");
        if (f != NULL) {
            return full_path;
        }
            
        llvm::errs() << "  Not found\n";
    }
    return basename;
}

void MLWVM::findImplibs() {
    auto globcount = module->getNamedGlobal("__vm_implibs_count");
    if (!globcount) {
        llvm::errs() << "Couldn't find import library count\n";
        std::abort();
    }
    auto initcount = globcount->getInitializer();
    if (auto* constint = llvm::dyn_cast<llvm::ConstantInt>(initcount)) {
        num_implibs = constint->getZExtValue();
    }

    for (int i = 0; i < num_implibs; i++) {
        auto implib_var = module->getNamedGlobal("__vm_implibs." + std::to_string(i));
        if (!implib_var) {
            llvm::errs() << "Import Library Count Variable (__vm_implibs_count) contains incorrect value\n";
            std::abort();
        }

        auto implib_initializer = implib_var->getInitializer();
        if (auto* constint = llvm::dyn_cast<llvm::ConstantDataArray>(implib_initializer)) {
            implibs.push_back(constint->getAsString().str());
        }
    }

    llvm::errs() << "Found " << num_implibs << " import libraries:\n";
    for (const auto& lib : implibs) {
        llvm::errs() << "  - " << lib << "\n";
    }
}