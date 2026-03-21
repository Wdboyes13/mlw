/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   IR Generation Helpers (helpers.cpp) */

#include "../gen_llvm.hpp"

// Helper methods
llvm::Type* LLVMGen::getType(const std::string& typeName) {
    auto i8type = llvm::Type::getInt8Ty(*ctx);
    if (typeName == "i32")
        return llvm::Type::getInt32Ty(*ctx);
    if (typeName == "i64")
        return llvm::Type::getInt64Ty(*ctx);
    if (typeName == "f32")
        return llvm::Type::getFloatTy(*ctx);
    if (typeName == "f64")
        return llvm::Type::getDoubleTy(*ctx);
    if (typeName == "bool")
        return llvm::Type::getInt1Ty(*ctx);
    if (typeName == "void")
        return llvm::Type::getVoidTy(*ctx);
    return llvm::Type::getInt32Ty(*ctx); // Default
}

llvm::Value* LLVMGen::popValue() {
    if (valueStacks.top().empty())
        return nullptr;
    auto val = std::move(valueStacks.top().top());
    valueStacks.top().pop();
    return val;
}

void LLVMGen::pushValue(llvm::Value* value) { valueStacks.top().push(value); }
