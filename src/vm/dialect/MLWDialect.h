#ifndef MLW_MLWDIALECT_H
#define MLW_MLWDIALECT_H

#include "mlir/IR/Dialect.h"
#include <mlir/IR/Region.h>
#include <mlir/IR/OpDefinition.h>
#include <mlir/Bytecode/BytecodeOpInterface.h>
#include <mlir/IR/Builders.h>

#define GET_OP_CLASSES
// Include the generated dialect declarations
#include "MLWDialect.h.inc"

// Include the generated operation declarations
#define GET_OP_CLASSES
#include "MLWOps.h.inc"

#endif // MLW_MLWDIALECT_H