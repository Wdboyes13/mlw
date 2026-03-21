set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(llvm REQUIRED CONFIG)
include(AddLLVM)

add_executable(${CMAKE_PROJECT_NAME}c
        driver.cpp
        gen_tree.cpp

        ir/arithmetic.cpp
        ir/vardef.cpp
        ir/function.cpp
        ir/init.cpp
        ir/helpers.cpp
        ir/import.cpp
        ir/debug.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME}c PRIVATE
        ${CMAKE_SOURCE_DIR}/src/antlr/gen
        ${antlr4-runtime_SOURCE_DIR}/runtime/src
        ${LLVM_INCLUDE_DIRS}
)

target_link_libraries(${CMAKE_PROJECT_NAME}c PRIVATE
        LLVMCore
        LLVMBinaryFormat
        LLVMBitWriter
        LLVMDemangle
        LLVMSupport
        antlr4_static
        mlwc_parser
)
