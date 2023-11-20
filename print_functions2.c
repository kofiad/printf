#include "main.h"

/**
 * print_number - prints a number send to this function
 * @args: List of arguments
 * Return: The number of arguments printed
 */
int print_number(va_list args)
{
	int n;
	int div;
	int length;
	unsigned int num;

	n  = va_arg(args, int);
	div = 1;
	length = 0;

	if (n < 0)
	{
		length += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		length += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (length);
}
/**
 * print_unsgined_number - Prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */
int print_unsigned_number(unsigned int n)
{
	int div;
	int length;
	unsigned int num;

	div = 1;
	length = 0;

	num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		length += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (length);
}
