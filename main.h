/*declaring header guards*/
#ifndef "MAIN_H"
#define "MAIN_H"

/*including standard C libraries*/
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/*define macros*/
#define UNUSED_VARIABLE(x) (void)(x)
#define BUFF_SIZE 1024

/*define FLAGS*/
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/*define SIZES*/
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * @struct FormatSpecifier - Structure to represent a format specifier
 * @specifier: format specifier character
 * @handler_fuction: functon associated with the specifier
 */
struct FormatSpecifier

{
	char specifier;
	int (*handler_function)(va_list, char[], int, int, int, int);
};

/**
 * @typedef FormatSpecifier format_t - Typedef for the FormatSpecifier structure
 */
typedef struct FormatSpecifier format_t;

int _printf(const char *format, ...);
int process_format(const char *specifier, int *index, va_list arguments, char buffer[], int flags, int width, int precision, int size);

/*function implementatio*/


#endif 
