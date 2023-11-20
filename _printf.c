#include "main2.h"
#include <stdarg.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
/**
 * _printf - a function that produces output according to a format
 * @format: is a character string
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list format_specifiers;
	int num, len;
	char *buffer;

	va_start(format_specifiers, format);

	while (*format)
	{

		switch (*format)
		{
			case ('%'):
				case ('d'):
					num = va_arg(format_specifiers, int);
					write(1, num, 1);
					break;
			default:
				write(1, format, 1);
				break;
		}

		format++;
	}
	va_end(format_specifiers);
}
