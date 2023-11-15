#include "main.h"

void _printf_buffer(char buffer[], int *buffer_index);
/**
 * _printf - a function that produces output according to a format
 * @format: is a character string
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int count, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (count = 0; format && format[count] != '\0'; i++)
	{
		if (format[count] != '%')
		{
			buffer[buffer_index++] = format[count];
			if (buffer_index == BUFFER_SIZE)
				_printf_buffer(buffer, &buffer_index);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			_printf_buffer(buffer, &buffer_index);
			flags = extract_flags(format, &count);
			width = extract_width(format, &count, args);
			precision = extract_precision(format, &count, args);
			size = extract_size(format, &count);
			++count;
			printed = handle_print(format, &count, args, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buffer_index);

	va_end(args);

	return (printed_chars);
}

/**
 * _printf_buffer - prints the contents of the _printf buffer
 * @buffer: array of chars
 * @buffer_index: represents the length.
 */
void _printf_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
