#include "main.h"

/**
 * print_string - prints string
 * @ags: va_list arguments
 * @p: pointer to the struct Flag
 * Return: number of char printed
 */
int print_string(va_list ags, flag_t *p)
{
	char *s = va_arg(ags, char *);

	(void)p;

	if (!s)
		s = "(null)";
	return (_puts(s));
}

/**
 * print_character - prints a character
 * @ags: va_list arguments
 * @p: pointer to the struct Flag
 * Return: number of char printed
 */
int print_character(va_list ags, flag_t *p)
{
	(void)p;
	_putchar(va_arg(ags, int));
	return (1);
}

/**
 * print_percent - prints a percent
 * @ags: va_list arguments
 * @p: pointer to the struct Flag
 * Return: number of char printed
 */
int print_percent(va_list ags, flag_t *p)
{
	(void)ags;
	(void)p;
	return (_putchar('%'));
}
