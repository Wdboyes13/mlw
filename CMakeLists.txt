cmake_minimum_required(VERSION 3.10)
project(mlw)

include(FetchContent)
FetchContent_Declare(
    antlr4-runtime
    URL https://www.antlr.org/download/antlr4-cpp-runtime-4.13.2-source.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(antlr4-runtime)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set_property(DIRECTORY "${CMAKE_SOURCE_DIR}" PROPERTY
    ADDITIONAL_CLEAN_FILES "${CMAKE_SOURCE_DIR}/bin" "${CMAKE_SOURCE_DIR}/target"
)

add_subdirectory(src)
