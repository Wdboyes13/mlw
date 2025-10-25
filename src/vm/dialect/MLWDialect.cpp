#include "MLWDialect.h"

#include <mlir/IR/Region.h>
#include <mlir/IR/Dialect.h>
#include <mlir/Tools/Plugins/DialectPlugin.h>

#define GET_OP_CLASSES
// Include the generated dialect definitions
#include "MLWDialect.cpp.inc"

#define GET_OP_CLASSES
// Include the generated operation definitions
#include "MLWOps.cpp.inc"

void mlw::MLWDialect::initialize() {
    addOperations<
        #define GET_OP_LIST
        #include "MLWOps.cpp.inc"
        >();
}

::mlir::LogicalResult mlw::ImplibsOp::verify() {
    // Check that libraries attribute exists and is an array
    auto libraries = getLibrariesAttr();
    if (!libraries)
        return emitOpError("requires 'libraries' attribute");

    // Check that all elements are strings
    for (auto lib : libraries) {
        if (!lib.isa<mlir::StringAttr>()) {
            return emitOpError("all library names must be strings");
        }
    }

    return mlir::success();
}
