# ===== helper functions =======

function(add_executable_config TARGETNAME)
    target_compile_options(${TARGETNAME} PRIVATE
        -Wall -Wextra -pedantic -Werror
        -Wno-unused-variable
        -Wno-unused-parameter
        -Wno-empty-body
        -Wno-sign-compare
        -Wno-missing-field-initializers
        -Wno-unused-function
        -Wno-unused-private-field
        -Wno-vla
        -O4
        )
    set_target_properties(${TARGETNAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
            "${PROJECT_BINARY_DIR}/bin")
endfunction()

add_executable(gemm gemm.cpp)
add_executable_config(gemm)

add_executable(quick_sort quick_sort.cpp)
add_executable_config(quick_sort)

add_executable(ackermann ackermann.cpp)
add_executable_config(ackermann)