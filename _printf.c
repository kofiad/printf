include "main.h"

/**
 * _printf - a function that produces output according to a format
 * @format: is a character string
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int (*function_pointer, Flag_t *);
	va_list args;
	const char *w;
	Flag_t Flag = {0, 0, 0,};

	register int char_count = 0;

	va_start(args, format);

		if ((format[0]  == '%' && *!format[1]) || !format)
			return (-1);
		if (format[0] == '%' && format[1] == ' ' && !format[2])
			return (-1);
		for (w = format; *w; w++)
		{
			if (*w == '%')
			{
				if (*w == '%')
				{
					char_count += _putchar('%');
					continue;
				}
				while (extract_flag(*w, &flag))
					w++;
				pointer_function = extract_print(*w);
				char_count += pointer_function
					? pointer_function(args, &flag)
					: _printf("%%%c", *w);
			}
		else
			char_count += _putchar(*w);
		}
		_putchar(-1);
		va_end(args);
		return (char_count);
}
