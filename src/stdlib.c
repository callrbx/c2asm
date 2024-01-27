/*
 * @file stdlib.c
 * standard libc compatibility layer
 */

#include "syscall-stubs.h"
#include <c2asm/stdlib.h>
#include <syscall.h>

void exit(int status)
{
    syscall1(SYS_exit, status);
}
