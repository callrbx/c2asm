/*
 * @file syscall-stubs.c
 * i386 inline asm syscall stub
 */

#include "syscall-stubs.h"

int syscall0(long number)
{
    int result;

    __asm__("int $0x80" : "=a"(result) : "a"(number) : "memory");

    return result;
}
