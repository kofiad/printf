#include "main.h"

/**
 * extract_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @index: List of arguments to be printed.
 * @arguments: list of arguments.
 *
 * Return: width.
 */
int extract_width(const char *format, int *index, va_list arguments)
{
	int current_index;
	int width = 0;

	for (current_index = *index + 1; format[current_index] != '\0';
			current_index++)
	{
		if (is_digit(format[current_index]))
		{
			width *= 10;
			width += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(arguments, int);
			break;
		}
		else
			break;
	}

	*index = current_index - 1;

	return (width);
}
