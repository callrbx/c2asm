/*
 * @file string.c
 * standard string manipulation functions
 */

#include <c2asm/string.h>
#include <c2asm/unistd.h>

size_t strlen(str) const char *str;
{
    register const char *s;

    for (s = str; *s; ++s)
        ;
    return (s - str);
}