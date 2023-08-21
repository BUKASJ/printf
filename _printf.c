#include <stdarg.h>
#include <unistd.h>
/**
 * main: main function
 * _putchar: vdfcdsbfcjb
 * _printf: sdjhcdsfh
 * Return: printed chars
 */

int _putchar(char c)
{
return write(1, &c, 1);
}
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
const char *c = format;
while (*c != '\0')
{
if (*c == '%')
{
c++;
if (*c == 'c')
{
char ch = va_arg(args, int);
_putchar(ch);
count++;
}
else if (*c == 's')
{
char *str = va_arg(args, char *);
for (int i = 0; str[i] != '\0'; i++)
{
_putchar(str[i]);
count++;
}
}
else if (*c == '%')
{
_putchar('%');
count++;
}
}
else
{
_putchar(*c);
count++;
}
c++;
}
va_end(args);
return count;
}
int main()
{
_printf("Hello, %s!\n", "world");
_printf("Character: %c\n", 'A');
_printf("Escaped percent: %%\n");
return 0;
}
