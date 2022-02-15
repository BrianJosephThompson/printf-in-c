#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define INT_BASE 10
#define OCT_BASE 8
#define HEX_BASE 16
#define SPECIFIER_VARIATIONS 7
#define MAX_BUFFER 100
#define NULLPTR 0

int (*print_func(char specifier, int size))(va_list);
int my_printf(char * restrict format, ...);
char hex_digit(int v);
int num_len(int n, int base);

#endif