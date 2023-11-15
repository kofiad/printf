#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED_PARAM(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct FormatSpecifier - Structure to represent a format specifier
 * @specifier: The format specifier character.
 * @handler_function: The function associated with the specifier.
 */
struct FormatSpecifier
{
	char specifier;
	int (*handler_function)(va_list, char[], int, int, int, int);
};

/**
 * typedef FormatSpecifier format_t - Typedef for the FormatSpecifier structure
 */
typedef struct FormatSpecifier format_t;

int my_printf(const char *format, ...);
int process_format(const char *specifier, int *index, va_list arguments,
		char buffer[], int flags, int width, int precision, int size);

/*FUNCTION IMPLEMENTATIONS*/

/*Character and string printing functions*/
int print_character(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_string(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_percent(va_list args, char buffer[], int flags, int width,
		int precision, int size);

/*Number printing functions*/
int print_integer(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_binary(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_unsigned(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_octal(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_hexadecimal(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int print_hex_upper(va_list args, char buffer[], int flags, int width,
		int precision, int size);

/*Non-printable character handling*/
int print_non_printable(va_list args, char buffer[], int flags,
		int width, int precision, int size);

/*Memory address printing*/
int print_memory_address(va_list args, char buffer[], int flags,
		int width, int precision, int size);

/*Other specifier handling functions*/
int extract_flags(const char *format, int *index);
int extract_width(const char *format, int *index, va_list arguments);
int extract_precision(const char *format, int *index, va_list arguments);
int extract_size(const char *format, int *index);

/*Reverse string printing function*/
int print_reversed(va_list args, char buffer[], int flags, int width,
		int precision, int size);

/*Rot13 string printing function*/
int print_rot13_string(va_list args, char buffer[], int flags, int width,
		int precision, int size);

/*Width handler functions*/
int handle_char_write(char c, char buffer[], int flags, int width,
		int precision, int size);
int write_number(int is_positive, int index, char buffer[], int flags,
		int width, int precision, int size);
int write_num(int index, char buffer[], int flags, int width,
		int precision, int length, char padding, char extra_char);
int write_memory_address(char buffer[], int index, int length, int width,
		int flags, char padding, char extra_char, int padding_start);
int write_unsigned(int is_negative, int index, char buffer[], int flags,
		int width, int precision, int size);

/*UTILITY FUNCTIONS*/
int is_printable_char(char character);
int append_hex_code(char character, char buffer[], int index);
int is_digit_char(char character);

long int convert_size_number(long int number, int size);
long int convert_size_unsigned(unsigned long int number, int size);

#endif /* MY_PRINT_UTILS_H */
