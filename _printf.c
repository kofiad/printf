include "main.h"

/**
 * _printf - a function that produces output according to a format
 * @format: is a character string
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int char_count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;/*move past '%'*/
			switch (*format)
			{
				case 'c':
					char_count += write(1, &va_arg(args, int), 1);
				break;
				case 's':
				char_count += write(1, va_arg(args, char*), write(va_arg(args, char*), 1));
				break;
				case '%';
				char_count += write(1, "%", 1);
				break;
				default:
				write(1, format, 1);
				char_count++;
			}
		}
		else
		{
			write(1, format, 1);
			char_count++;
		}
		format++;
	}
	va_end(args);
	return (char_count);
}
