cmake_minimum_required(VERSION 3.10)
project(mlw)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(mlir REQUIRED CONFIG)

list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
include(AddMLIR)

add_library(
        MLWDialect STATIC
        src/vm/dialect/MLWDialect.h
        src/vm/dialect/MLWDialect.cpp
)

target_include_directories(MLWDialect PRIVATE
        ${MLIR_INCLUDE_DIRS}
        ${LLVM_INCLUDE_DIRS}
)

target_link_libraries(MLWDialect PRIVATE
        MLIR
        LLVMSupport
        LLVMDemangle
)

add_executable(${CMAKE_PROJECT_NAME}c
        src/antlr/gen/MLWBaseListener.cpp
        src/antlr/gen/MLWLexer.cpp
        src/antlr/gen/MLWListener.cpp
        src/antlr/gen/MLWParser.cpp

        src/codegen/driver.cpp
        src/codegen/gen_tree.cpp

        src/codegen/mlir/arithmetic.cpp
        src/codegen/mlir/vardef.cpp
        src/codegen/mlir/function.cpp
        src/codegen/mlir/init.cpp
        src/codegen/mlir/helpers.cpp
        src/codegen/mlir/import.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME}c PRIVATE
        src/antlr/gen
        ${MLIR_INCLUDE_DIRS}
        ${LLVM_INCLUDE_DIRS}
        lib/antlr4/antlr4-runtime
        src/vm/dialect
)

target_link_directories(${CMAKE_PROJECT_NAME}c PRIVATE
        lib/antlr4/lib
)

target_link_libraries(${CMAKE_PROJECT_NAME}c PRIVATE
        MLIR
        MLIRBytecodeWriter
        LLVMDemangle
        LLVMSupport
        antlr4-runtime
        MLWDialect
        MLIRFuncDialect
        MLIRArithDialect
)

add_executable(${CMAKE_PROJECT_NAME}
        src/vm/vmmain.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        ${MLIR_INCLUDE_DIRS}
        ${LLVM_INCLUDE_DIRS}
        src/vm/dialect
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        MLIR
        MLIRBytecodeReader
        MLIRParser
        LLVMSupport
        LLVMDemangle
        MLIRExecutionEngine
        MLIRFuncDialect
        MLIRArithDialect
        MLIRLLVMDialect
        MLIRExecutionEngineUtils
        MLWDialect
)