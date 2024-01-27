cmake_minimum_required(VERSION 3.14)

project(
    c2asm
    VERSION 0.1
    DESCRIPTION "Simple project to build C as PIC blobs"
    LANGUAGES CXX
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(C2ASM_PUBLIC_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include/)

set(COMMON_SOURCE_FILES src/unistd.c src/stdlib.c src/stdio.c src/string.c)

set(ARCH_SOURCE_FILES src/arch/x86_64/syscall-stubs.c)

add_library(c2asm STATIC "${COMMON_SOURCE_FILES}" "${ARCH_SOURCE_FILES}")
set_target_properties(c2asm PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(c2asm PUBLIC ${C2ASM_PUBLIC_INCLUDE_DIRS})
target_include_directories(c2asm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/)