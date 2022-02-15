# My Printf Recreation

This project is a recreation of the famous printf function.

This project was completed on November 26th, 2021.

## Description

This function writes the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.

The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.

Each conversion specification is introduced by the % character. The arguments correspond with the conversion specifier. After the %, the following are options of coversion specifiers:

* d - The int argument is converted to signed decimal.
* o - The int argument is converted to unsigned octal.
* u - The int argument is converted to unsigned decimal.
* x - The int argument is converted to unsigned hexadecimal.
* c - The int argument is converted to an unsigned char, and the resulting character is written.
* s - The char * argument is a be a pointer to an array of character type. Characters from the array are written up to (but not including) the terminating NUL character.
* p - The void * pointer argument is converted to hexadecimal.

## Usage

In the printf.c file, the main function at the end of the file is intended for testing the printf recreation. The name of the function is my_printf. Feel free to explore each of the conversion specifiers indicated above.

```
int main()
{
    my_printf("Hello world!\n");
    printf("Hello World!\n");

    my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o');
    printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o');
}
```

Above are a couple of examples to test the function and compare it to the standard printf function. Any of the other conversion specifiers mentioned in the description section may be utilized.

Upon updating the main function in the printf.c file you are ready to compile and test.

`$ make printf`