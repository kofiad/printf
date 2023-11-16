#include "main.h"

/**
 * _parser - Receives the main string and necessary
 * parameters to print a formated string.
 * @format: A string containing all the desired characters.
 * @func_list: A list of all the posible functions.
 * @arg_list: A list containing all the argumentents passed to the program
 * Return: A total count of the characters printed.
 */
int _parser(const char *format, format_t func_list[], va_list arg_list)
{
	int i, j, r_val, char_count;

	char_count = 0;
	for (i = 0; format[i] != '\0'; i++)/* Iterates through the main str*/
	{
		if (format[i] == '%') /*Checks for format specifiers*/
		{
			/*Iterates through struct to find the right func*/
			for (j = 0; func_list[j].spec != NULL; j++)
			{
				if (format[i + 1] == func_list[j].spec[0])
				{
					r_val = func_list[j].func(arg_list);
					if (r_val == -1)
						return (-1);
					char_count += r_val;
					break;
				}
			}
			if (func_list[j].spec == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					char_count = char_count + 2;
				}
				else
					return (-1);
			}
			i = i + 1; /*Updating i to skip format symbols*/
		}
		else
		{
			_putchar(format[i]); /*call the write function*/
			char_count++;
		}
	}
	return (char_count);
}
