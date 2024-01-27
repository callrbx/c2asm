/*
 * @file syscall-stubs.c
 * x86_64 inline asm syscall stub
 */

#include "syscall-stubs.h"

int syscall0(long number)
{
    long result;
    __asm__("syscall" : "=a"(result) : "a"(number) : "rcx", "r11", "memory");
    return (int)result;
}

int syscall1(long number, long arg1)
{
    long result;
    __asm__("syscall" : "=a"(result) : "a"(number), "D"(arg1) : "rcx", "r11", "memory");
    return (int)result;
}

int syscall2(long number, long arg1, long arg2)
{
    long result;
    __asm__("syscall" : "=a"(result) : "a"(number), "D"(arg1), "S"(arg2) : "rcx", "r11", "memory");
    return (int)result;
}

int syscall3(long number, long arg1, long arg2, long arg3)
{
    long result;
    __asm__("syscall" : "=a"(result) : "a"(number), "D"(arg1), "S"(arg2), "d"(arg3) : "rcx", "r11", "memory");
    return (int)result;
}

int syscall4(long number, long arg1, long arg2, long arg3, long arg4)
{
    long result;

    __asm__("mov %4, %%r10\n"
            "syscall"
            : "=a"(result)
            : "a"(number), "D"(arg1), "S"(arg2), "d"(arg3), "r"(arg4)
            : "rcx", "r11", "r10", "memory");

    return (int)result;
}

int syscall5(long number, long arg1, long arg2, long arg3, long arg4, long arg5)
{
    long result;

    __asm__("mov %4, %%r10\n"
            "mov %5, %%r8\n"
            "syscall"
            : "=a"(result)
            : "a"(number), "D"(arg1), "S"(arg2), "d"(arg3), "r"(arg4), "r"(arg5)
            : "rcx", "r11", "r10", "r8", "memory");

    return (int)result;
}
