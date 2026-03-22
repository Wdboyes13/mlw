if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CARGO_CMD cargo build --release)
    set(CARGO_TARGET_DIR ${CMAKE_SOURCE_DIR}/target/release)
else()
    set(CARGO_CMD cargo build)
    set(CARGO_TARGET_DIR ${CMAKE_SOURCE_DIR}/target/debug)
endif()

add_custom_command(
    OUTPUT ${CARGO_TARGET_DIR}/mlwpp
    COMMAND ${CARGO_CMD}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    DEPENDS ${CMAKE_SOURCE_DIR}/src/preproc/main.rs
    COMMENT "building mlwpp via cargo"
)

add_custom_command(
    OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mlwpp
    COMMAND ${CMAKE_COMMAND} -E copy ${CARGO_TARGET_DIR}/mlwpp ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mlwpp
    DEPENDS ${CARGO_TARGET_DIR}/mlwpp
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "copying mlwpp binary"
)

add_custom_target(mlwpp ALL
    DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mlwpp
)
