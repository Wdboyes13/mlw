set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(mlwc_parser STATIC gen/MLWBaseListener.cpp gen/MLWLexer.cpp gen/MLWListener.cpp gen/MLWParser.cpp)

target_include_directories(mlwc_parser PRIVATE
        ${CMAKE_SOURCE_DIR}/src/antlr/gen
        ${antlr4-runtime_SOURCE_DIR}/runtime/src
)
