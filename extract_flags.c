#include "main.h"

/**
 * extract_flags - Calculates active flags
 * @format: Formatted string to print the arguments
 * @index: parameter.
 * Return: Flags:
 */
int extract_flags(const char *format, int *index)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int i, current_index;
	int flags = 0;
	const char FLAGS_CHARACTER[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_index = *i + 1; format[currect_index] != '\0'; current_index++)
	{
		for (i = 0; FLAGS_CHARACTER[i] != '\0'; i++)
			if (format[current_index] == FLAGS_CHARACTER[i])
			{
				flags |= FLAGS_ARRAY[i];
				break;
			}

		if (FLAGS_CHARACTER[i] == 0)
			break;
	}

	*index = current_index - 1;

	return (flags);
}
