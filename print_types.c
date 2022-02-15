#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include "print_types.h"
#include "functions.h"

int print_d(va_list argument_specifier)
{
    int num;
	int div = 1;
	int len = 0;
	unsigned int n;
    num = va_arg(argument_specifier, int);
    if (num < 0)
    {
        putchar('-');
        n = -1 * num;
    }
    else
    {
        n = num;
    }
	while (n / div > 9)
		div *= INT_BASE;
	while (div != 0)
	{
		len += putchar('0' + n / div);
		n %= div;
		div /= INT_BASE;
	}
    len = num_len(num, INT_BASE);
	return (len);
}

int print_o(va_list argument_specifier)
{
    int num;
	int div = 1;
	int len = 0;
	unsigned int n;
    num = va_arg(argument_specifier,unsigned int);
    n = num;

	while (n / div > 7)
		div *= OCT_BASE;
	while (div != 0)
	{
		len += putchar('0' + n / div);
		n %= div;
		div /= OCT_BASE;
	}
    len = num_len(num, OCT_BASE);
	return (len);
}

int print_u(va_list argument_specifier)
{
    int num;
	int div = 1;
	int len = 0;
	unsigned int n;
    num = va_arg(argument_specifier,unsigned int);
    n = num;

	while (n / div > 9)
		div *= INT_BASE;
	while (div != 0)
	{
		len += putchar('0' + n / div);
		n %= div;
		div /= INT_BASE;
	}
    len = num_len(num, INT_BASE);
	return (len);
}

int print_x(va_list argument_specifier)
{
    long int hex;
    hex = va_arg(argument_specifier, long int);

    long int quotient;
    int i = 1, j, temp;
    char hexNum[MAX_BUFFER];
    quotient = hex;
    while(quotient != 0)
    {
        temp = quotient % HEX_BASE;
        if( temp < 10)
            temp = temp + 48;
        else
        {
            temp = temp + 55;
        }
        hexNum[i++] = temp;
        quotient = quotient / HEX_BASE;
    }
    for (j = i - 1; j > 0; j--)
    {
        putchar(hexNum[j]);
    }
    return (i-1);
}

int print_c(va_list argument_specifier)
{
    putchar(va_arg(argument_specifier, int));
    return (1);
}

int print_s(va_list argument_specifier)
{
    int i;
    char* str;

    str = va_arg(argument_specifier, char *);
    if(str == NULL)
        str = "(null)";
    for (i = 0; str[i] != '\0'; i++)
        putchar(str[i]);
    return (i);
}

int print_p(va_list argument_specifier)
{
    int i;
    int count = 2;
    uintptr_t p = va_arg(argument_specifier, uintptr_t);

    putchar('0'); putchar('x');
    for(i = (sizeof(p) << 3)- 20; i >= 0; i -= 4)
    {
        count++;
        putchar(hex_digit((p >> i) & 0xf));
    }
    return (count);
}