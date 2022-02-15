#ifndef PRINT_TYPES_H
#define PRINT_TYPES_H

typedef struct print_specifier
{
    char specifier;
    int (*func)(va_list);
} print_type;

int print_d(va_list argument_specifier);
int print_o(va_list argument_specifier);
int print_u(va_list argument_specifier);
int print_x(va_list argument_specifier);
int print_c(va_list argument_specifier);
int print_s(va_list argument_specifier);
int print_p(va_list argument_specifier);


#endif