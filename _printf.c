#include <stdio.h>
#include <stdarg.h>
/**
 * _printf: printf function
 * main: main fuction
 * Return: always 0
 */

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;

switch (*format)
{
case 'c':
	{
char c = (char) va_arg(args, int);
putchar(c);
break;
}
case 'd':
{
int d = va_arg(args, int);
printf("%d", d);
break;
}
case 's':
{
char *s = va_arg(args, char *);
printf("%s", s);
break;
}
default:
putchar(*format);
}
}
else
{
putchar(*format);
}
format++;
}
va_end(args);
}
int main(void)
{
int num = 42;
char letter = 'A';
char string[] = "Hello, world!";
_printf("Number: %d\nCharacter: %c\nString: %s\n", num, letter, string);
return (0);
}
