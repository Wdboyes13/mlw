cmake_minimum_required(VERSION 3.10)
project(mlw)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(llvm REQUIRED CONFIG)
include(AddLLVM)

add_executable(${CMAKE_PROJECT_NAME}c
        src/antlr/gen/MLWBaseListener.cpp
        src/antlr/gen/MLWLexer.cpp
        src/antlr/gen/MLWListener.cpp
        src/antlr/gen/MLWParser.cpp

        src/codegen/driver.cpp
        src/codegen/gen_tree.cpp

        src/codegen/ir/arithmetic.cpp
        src/codegen/ir/vardef.cpp
        src/codegen/ir/function.cpp
        src/codegen/ir/init.cpp
        src/codegen/ir/helpers.cpp
        src/codegen/ir/import.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME}c PRIVATE
        src/antlr/gen
        ${LLVM_INCLUDE_DIRS}
        lib/antlr4/antlr4-runtime
)

target_link_directories(${CMAKE_PROJECT_NAME}c PRIVATE
        lib/antlr4/lib
)

target_link_libraries(${CMAKE_PROJECT_NAME}c PRIVATE
        LLVMCore
        LLVMBinaryFormat
        LLVMBitWriter
        LLVMDemangle
        LLVMSupport
        antlr4-runtime
)

add_executable(${CMAKE_PROJECT_NAME}
        src/vm/vmmain.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        ${LLVM_INCLUDE_DIRS}
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        LLVMTarget
        LLVMCodegen
        LLVMCore
        LLVMSupport
        LLVMDemangle
        LLVMLinker
        LLVMExecutionEngine
        LLVMRuntimeDyld
        LLVMOrcJIT
        LLVMAArch64AsmParser
        LLVMAArch64CodeGen
        LLVMAArch64Info
)