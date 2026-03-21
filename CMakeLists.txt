cmake_minimum_required(VERSION 3.10)
project(mlw)

include(FetchContent)
FetchContent_Declare(
    antlr4-runtime
    URL https://www.antlr.org/download/antlr4-cpp-runtime-4.13.2-source.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(antlr4-runtime)

add_subdirectory(src)
