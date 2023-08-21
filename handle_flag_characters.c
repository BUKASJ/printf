#include <stdio.h>
#include <stdarg.h>

void _printf(const char *format, ...)
{
va_list args;
var_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'd' || *format == 'i')
{
int value = var_arg(args, int);
printf("%d", value);
}
else
{
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
int number1 = 42;
int number2 = -123;
_printf("Number 1: %d\nNumber 2: %i\n", number1, number2);
return (0);
}
