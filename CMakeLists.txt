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
        src/codegen/ir/debug.cpp
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
        src/vm/vm_main.cpp
        src/vm/vm_run.cpp
        src/vm/vm_link.cpp
        src/vm/vm_init.cpp
        src/vm/vm_finalize.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        ${LLVM_INCLUDE_DIRS}
)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|i[3456]86")
    set(LLVM_TARGET "X86")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64")
    set(LLVM_TARGET "AArch64")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "arm|armv7")
    set(LLVM_TARGET "ARM") 
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "ppc|powerpc")
    set(LLVM_TARGET "PowerPC")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "riscv")
    set(LLVM_TARGET "RISCV")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "mips")
    set(LLVM_TARGET "Mips")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "sparc")
    set(LLVM_TARGET "Sparc")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "s390")
    set(LLVM_TARGET "SystemZ")
else()
    message(FATAL_ERROR "Unable to identify your CPU Architecture")
endif()

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
        LLVM${LLVM_TARGET}AsmParser
        LLVM${LLVM_TARGET}CodeGen
        LLVM${LLVM_TARGET}Info
)