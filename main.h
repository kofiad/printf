#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct FormatSpecifier - Structure for symbols and functions
 * @spec: The format specifier character.
 * @func: The function associated with the specifier.
 */
struct FormatSpecifier
{
	char *spec;
	int (*func)(va_list);
};

/**
 * typedef FormatSpecifier format_t - Typedef for the FormatSpecifier structure
 */
typedef struct FormatSpecifier format_t;

/*FUNCTION PROTOTYPES*/
int _printf(const char *format, ...);
int _parser(const char *format, format_t func_list[], va_list arg_list);

/*Character and string functions*/
int _putchar(char);
int print_character(va_list);
int print_string(va_list);
int print_percent(va_list);

/*Number printing functions*/
int print_integer(va_list);
int print_binary(va_list);
int print_unsigned(va_list);
int print_octal(va_list list);
int print_hexadecimal(va_list list);
int print_hex_upper(va_list list);
int print_number(va_list);

/*Reverse string printing function*/
int print_reversed(va_list args);

/*Rot13 string printing function*/
int print_rot13_string(va_list);

/*UTILITY FUNCTIONS*/
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsigned_number(unsigned int);
char *rev_string(char *s);
unsigned int base_length(unsigned int, int);
void write_base(char *str);
#endif /* MAIN_H */
