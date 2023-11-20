#include "main.h"
/**
 * _printf - a function that produces output according to a format
 * @format: is a character string
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...)
{
	int char_count;
	format_t func_list[] = {
		{"c", print_character},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_number},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hexadecimal},
		{"X", print_hex_upper},
		{"r", print_reversed},
		{"R", print_rot13_string},
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start (arg_list, format);
	/*utilizing parser function*/
	char_count = _parser(format, func_list, arg_list);
	va_end(arg_list);
	return (char_count);
}
