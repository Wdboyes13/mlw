#include "../gen_mlir.hpp"

// Helper methods
Type MLIRGen::getType(const std::string& typeName) {
    if (typeName == "i32") return builder.getI32Type();
    if (typeName == "i64") return builder.getI64Type();
    if (typeName == "f32") return builder.getF32Type();
    if (typeName == "f64") return builder.getF64Type();
    if (typeName == "str") return builder.getI32Type(); // Placeholder
    if (typeName == "bool") return builder.getI1Type();
    if (typeName == "void") return builder.getNoneType();
    return builder.getI32Type(); // Default
}

Value MLIRGen::popValue() {
    if (valueStacks.top().empty()) return nullptr;
    auto val = valueStacks.top().top();
    valueStacks.top().pop();
    return val;
}

void MLIRGen::pushValue(Value value) {
    valueStacks.top().push(value);
}