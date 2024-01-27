cmake_minimum_required(VERSION 3.14)

project(
    c2asm
    VERSION 0.1
    DESCRIPTION "Simple project to build C as PIC blobs"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(C2ASM_PUBLIC_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include/)

set(COMMON_SOURCE_FILES src/unistd.c src/stdlib.c src/stdio.c src/string.c)

set(ARCH_SOURCE_FILES src/arch/x86_64/syscall-stubs.c)

add_library(c2asm STATIC ${COMMON_SOURCE_FILES} ${ARCH_SOURCE_FILES})
set_target_properties(c2asm PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(c2asm PUBLIC ${C2ASM_PUBLIC_INCLUDE_DIRS})
target_include_directories(c2asm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/CreateFlatBinary.cmake
"function(create_blob target_name source_files blob_name)
    # Ensure target is already defined
    if(TARGET \${target_name})
        message(FATAL_ERROR 'Target \${target_name} already exists')
    endif()
    add_executable(\${target_name} \${source_files})
    set_target_properties(\${target_name} PROPERTIES POSITION_INDEPENDENT_CODE ON)
    target_link_libraries(\${target_name} c2asm)
    set_target_properties(\${target_name} PROPERTIES LINK_FLAGS \"-T \${CMAKE_SOURCE_DIR}/linker.ld -nostartfiles\")
    add_custom_command(TARGET \${target_name} POST_BUILD
        COMMAND \${CMAKE_OBJCOPY} -O binary -j .text -j .data -j .bss -j .rodata \$<TARGET_FILE:\${target_name}> \${CMAKE_CURRENT_BINARY_DIR}/\${blob_name}
        COMMENT \"Creating flat binary file\")
endfunction(create_blob)"
)
