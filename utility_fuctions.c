#include "main.h"
#include <stdio.h>

/**
 * write_base - sends characters to be written to stdout
 * @str: string to parse
 */
void write_base(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * _memcpy - copies n bytes from memory area
 * src to memory area dest
 * @n: bytes to be copied
 * @src: source memory area
 * @dest: destination memory area
 * Return: *dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r, s = n;

	for (; r < s; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 * Return: void
 */
char *rev_string(char *s)
{
	int l, LengthOfString = 0;
	char k;

	if (s != NULL)
	{
		while (s[LengthOfString] != '\0')
		{
			LengthOfString++;
		}
		for (l = 0; l < LengthOfString / 2; l++)
		{
			k = s[l];
			s[l] = s[LengthOfString - 1 - l];
			s[LengthOfString - 1 - l] = k;
		}
	}
return (s);
}

/**
 * base_length - calculates octal number length
 * @num: number of interest
 * @base:base to be calculated
 * Return: length of number
 */
unsigned int base_length(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}
