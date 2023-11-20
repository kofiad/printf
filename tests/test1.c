#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	char c;

	c = 'B';
	write(1, &c, 1);
	write(1, "\n", 1);

	return (0);
}
