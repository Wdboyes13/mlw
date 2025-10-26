set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(llvm REQUIRED CONFIG)
include(AddLLVM)

add_executable(${CMAKE_PROJECT_NAME}
        vm_main.cpp
        vm_run.cpp
        vm_link.cpp
        vm_init.cpp
        vm_finalize.cpp
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