#include "main.h"

/**
 * extract_print - selects the right printing function
 * @flag: character that holds the conversion specifier
 * Return: a pointer to the matching printing function
 */
int (*extract_print(char flag))(va_list, Flag_t *)
{
	FS function_array[] = {
		{'s', print_string},
		{'c', print_character},
		{'%', print_percent},
		{'i', print_integer},
		{'d', print_integer},
		{'u', print_unsigned},
		{'x', print_hexadecimal},
		{'X', print_hex_upper},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13_string},
		{'r', print_reversed},
		{'p', print_memory_address},
		};
	int flags = 13;

	register int i;

	for (i = 0; i < flags; i++)
		if (function_array[i].f == flag)
			return (function_array[i].p);
	return (NULL);
