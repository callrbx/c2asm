/*
 * @file syscall-stubs.h
 * syscall stub definitions
 */

#ifndef __SYSCALL_STUBS_H__
#define __SYSCALL_STUBS_H__

int syscall0(long number);
int syscall1(long number, long arg1);
int syscall2(long number, long arg1, long arg2);
int syscall3(long number, long arg1, long arg2, long arg3);
int syscall4(long number, long arg1, long arg2, long arg3, long arg4);
int syscall5(long number, long arg1, long arg2, long arg3, long arg4, long arg5);

#endif // __SYSCALL_STUBS_H__