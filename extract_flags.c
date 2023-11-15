#include "main.h"

/**
 * get_flag - identifies flags
 * @flag: character that holds a flag specifier
 * @p: pointer to the struct flag
 * Return: 1 if a flag has been turned on
 * 0 otherwise
 */
int extract_flags(char flag, flag_t *p)
{
	int i = 0;

	switch (flag)
	{
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}
	return (i);
}
