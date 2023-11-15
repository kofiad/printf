#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct Flag - Structure to represent a flag
 * @plus: '+' flag
 * @hash: '#' flag
 * @space: ' ' flag
 */
struct Flag
{
	int space;
	int hash;
	int plus;
} Flag_t;

/**
 * struct FormatSpecifier - structure to represent the Format Specifier
 * @f: format specifier
 * @p: pointer to corresponding printing fuction
 */
typedef struct FormatSpecifier
{
	char f;
	int (*p)(va_list ag, Flag_t *p);
} FS;

/*function implementation*/
/*printf*/
int _printf(const char *format, ...);

/*character and string printing functions*/
int print_character(va_list ags, Flag_t *p);
int print_string(va_list ags, Flag_t *p);
int print_percent(va_list ags, Flag_t *p);

/*number printing fuctions*/
int print_integer(va_list ags, Flag_t *p);
int print_binary(va_list ags, Flag_t *p);
int print_unsigned(va_list ags, Flag_t *p);
int print_octal(va_list ags, Flag_t *p);
int print_hexadecimal(va_list ags, Flag_t *p);
int print_hex_upper(va_list ags, Flag_t *p);
int print_num(int n);
int num_counter(int i);

/*memory address printing*/
int print_memory_address(va_list ags, Flag_t *p);

/*other specifier handling functions*/
int extract_flags(char flag, Flag_t *p);
int (*extract_print(char flag))(va_list, Flag_t *);

/*reverse string printing function*/
int print_reversed(va_list ags, Flag_t *p);

/*rot13 string printing function*/
int print_rot13_string(va_list ags, Flag_t *p);

/*output write functions*/
int _putchar(char c);
int _puts(char *str);

/*utility functions*/
char conversion(unsigned long int num, int base, int small_letter);

#endif /*MAIN_H*/
