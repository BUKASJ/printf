#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf_char - Print a single character and update the count
 * @c: The character to be printed
 * @count: Pointer to the count of printed characters
 *
 * Return: 0.
 */

static int _printf_char(char c, int *count)
{
	_putchar(c);
	(*count)++;
	return (0);
}

/**
 * _printf_number - Print a number based on conversion specifier.
 * @args: The va_list containing the arguments
 * @specifier: The conversion specifier
 * @count: Pointer to the count of printed characters
 *
 * Return: The number of characters printed
 */

static int _printf_number(va_list args, char specifier, int *count)
{
	(void)count;

	if (specifier == 'd' || specifier == 'i')
	{
		int num = va_arg(args, int);

		return (printf("%d", num));
	}
	else if (specifier == 'u')
	{
		unsigned int num = va_arg(args, unsigned int);

		return (printf("%u", (unsigned int)num));
	}
	else if (specifier == 'o')
	{
		unsigned int num = va_arg(args, unsigned int);

		return (printf("%o", num));
	}
	else if (specifier == 'x')
	{
		unsigned int num = va_arg(args, unsigned int);

		return (printf("%x", num));
	}
	else if (specifier == 'X')
	{
		unsigned int num = va_arg(args, unsigned int);

		return (printf("%X", num));
	}
	return (0);
}

/**
 * _printf - Custom printf function with limited functionality.
 * @format: The format string.
 * @...: The variadic arguments.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'd' || *format == 'i' || *format == 'u' ||
			    *format == 'o' || *format == 'x' || *format == 'X')
			{
				count += _printf_number(args, *format, &count);
			}
			else
			{
				count += _printf_char('%', &count);
				count += _printf_char(*format, &count);
			}
		}

		else
		{
			count += _printf_char(*format, &count);
		}

		format++;
	}

	va_end(args);
	return (count);
}
