/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   IR Generation Helpers (helpers.cpp) */

#include "../gen_llvm.hpp"

// Helper methods
llvm::Type* LLVMGen::get_type(const std::string& typeName) {
    auto i8type = llvm::Type::getInt8Ty(*ctx);
    if (typeName == "i32") {
        return llvm::Type::getInt32Ty(*ctx);
    } else if (typeName == "i64") {
        return llvm::Type::getInt64Ty(*ctx);
    } else if (typeName == "f32") {
        return llvm::Type::getFloatTy(*ctx);
    } else if (typeName == "f64") {
        return llvm::Type::getDoubleTy(*ctx);
    } else if (typeName == "bool") {
        return llvm::Type::getInt1Ty(*ctx);
    } else if (typeName == "void") {
        return llvm::Type::getVoidTy(*ctx);
    } else {
        return llvm::Type::getInt32Ty(*ctx);
    }
}

llvm::Value* LLVMGen::pop_value() {
    if (value_stacks.top().empty()) {
        return nullptr;
    }
    auto val = std::move(value_stacks.top().top());
    value_stacks.top().pop();
    return val;
}

void LLVMGen::push_value(llvm::Value* value) { value_stacks.top().push(value); }
