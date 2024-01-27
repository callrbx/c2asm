/*
 * @file unistd.c
 * standard symbolic constants and types
 */

#include "syscall-stubs.h"
#include <c2asm/unistd.h>
#include <syscall.h>

ssize_t write(int fildes, const void *buf, size_t nbyte)
{
    return syscall3(SYS_write, fildes, (long int)buf, nbyte);
}
