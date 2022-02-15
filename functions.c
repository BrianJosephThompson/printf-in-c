#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "functions.h"

char hex_digit(int v) 
{
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10;
}

int my_strlen(char *s)
{
    char *p = s;
    
    while (*p != '\0')
        p++;
    return p - s;
}

int num_len(int n, int base)
{
    int i = 0;
    if(n < 0 || n == 0)
    {
        n = -n;
        i++;
    }
    for (; n > 0; i++)
    {
        n = n / base;
    }
    return i;
}