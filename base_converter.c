#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int hexadecimal_check(int, char);

/**
 * print_binary - Converts a number from base 10 to binary
 * @list: List of arguments passed to this function
 * Return: The length of the number printed
 */
int print_binary(va_list list)
{
	unsigned int num;
	int i, length;
	char *str;
	char *reverse_string;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	length = base_length(num, 2);
	str = malloc(sizeof(char) * length + 1);
	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num = num / 2;
	}
	str[i] = '\0';
	reverse_string = rev_string(str);
	if (reverse_string == NULL)
		return (-1);
	write_base(reverse_string);
	free(str);
	free(reverse_string);
	return (length);
}

/**
 * print_octal - Prints the a number in base 8
 * @list: List of all the arguments passed to the program
 * Return: Number of symbols printed to stdout
 */
int print_octal(va_list list)
{
	unsigned int num;
	int length;
	char *octal_rep;
	char *reverse_string;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	length = base_length(num, 8);

	octal_rep = malloc(sizeof(char) * length + 1);
	if (octal_rep == NULL)
		return (-1);
	for (length = 0; num > 0; length++)
	{
		octal_rep[length] = (num % 8) + 48;
		num = num / 8;

	}
	octal_rep[length] = '\0';
	reverse_string = rev_string(octal_rep);
	if (reverse_string == NULL)
		return (-1);

	write_base(reverse_string);
	free(octal_rep);
	free(reverse_string);
	return (length);
}

/**
 * print_hexadecimal - Prints a decimal number in base16 lowercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list list)
{
	unsigned int num;
	int length;
	int rem_num;
	char *hex_rep;
	char *reverse_hexadecimal;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	length = base_length(num, 16);
	hex_rep = malloc(sizeof(char) * length + 1);
	if (hex_rep == NULL)
		return (-1);
	for (length = 0; num > 0; length++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hexadecimal_check(rem_num, 'x');
			hex_rep[length] = rem_num;
		}
		else
			hex_rep[length] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[length] = '\0';
	reverse_hexadecimal = rev_string(hex_rep);
	if (reverse_hexadecimal == NULL)
		return (-1);
	write_base(reverse_hexadecimal);
	free(hex_rep);
	free(reverse_hexadecimal);
	return (length);
}


/**
 * print_hex_upper - Prints a number in base16 Uppercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_hex_upper(va_list list)
{
	unsigned int num;
	int length;
	int rem_num;
	char *hex_rep;
	char *reverse_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	length = base_length(num, 16);
	hex_rep = malloc(sizeof(char) * length + 1);
	if (hex_rep == NULL)
		return (-1);
	for (length = 0; num > 0; length++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hexadecimal_check(rem_num, 'X');
			hex_rep[length] = rem_num;
		}
		else
			hex_rep[length] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[length] = '\0';
	reverse_hex = rev_string(hex_rep);
	if (reverse_hex == NULL)
		return (-1);
	write_base(reverse_hex);
	free(hex_rep);
	free(reverse_hex);
	return (length);
}

/**
 * hexadecimal_check - Checks which hex function to call
 * @num: Number to convert into letter
 * @x: Tells which hex function to call
 * Return: ASCII value for a letter
 */
int hexadecimal_check(int num, char x)
{
	char *hexadecimal = "abcdef";
	char *hex_upper = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hexadecimal[num]);
	else
		return (hex_upper[num]);
	return (0);
}
