#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include "print_types.h"
#include "functions.h"


int (*print_func(char specifier, int size))(va_list)
{
    print_type feature_list[] =
    {
        {'d', print_d},
        {'o', print_o},
        {'u', print_u},
        {'x', print_x},
        {'c', print_c},
        {'s', print_s},
        {'p', print_p}
    };

    for(int index = 0; index < size; index++)
    {
        if(feature_list[index].specifier == specifier)
        {
            return feature_list[index].func;
        }
    }
    return NULLPTR;
}

int my_printf(char * restrict format, ...)
{
    int count = 0;
    va_list argument_specifier;

    va_start(argument_specifier, format);
    
    while(*format)
        if(*format == '%')
        {
            format++;
            count += (*print_func(*format, SPECIFIER_VARIATIONS))(argument_specifier);
            format++;
        }
        else
        {
            putchar(*format);
            format++;
            count++;
        }

    va_end(argument_specifier);
    
return count;
}

int main()
{
    my_printf("Hello world!\n");
    printf("Hello World!\n");

    my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o');
    printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o');



}