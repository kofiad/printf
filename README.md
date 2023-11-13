# 0x11. C - printf
## This is a group alx project to write a personal printf function. Project was done by Bright Sefah and Gilbert Henyo

## Introduction to printf and its purpose:
	printf is a function in C used for formatted output.
	It allows you to print various types of data (integers, floats, characters, strings, etc.) with specific formatting.
	The formatting is controlled by a format string that specifies placeholders for data and formatting options.


## Format strings and placeholders:
	A format string is a string containing format specifiers and optional text.
	Format specifiers are placeholders for data and start with a '%' character, followed by a character indicating the type of data to print (e.g., %d for integers).
	You can include regular characters in the format string, which will be printed as-is.


## Variadic arguments:
	printf accepts a variable number of arguments.
	It uses variadic functions, indicated by ... in the function signature.
	Variadic functions allow you to pass a variable number of arguments of different types.


## Parsing the format string:
	printf processes the format string character by character.
	When it encounters '%' followed by a format specifier, it knows what type of data to expect.
	It extracts arguments based on the format specifier and converts them to the specified type.


## Handling different format specifiers:
	printf supports various format specifiers (e.g., %d for integers, %f for floats, %c for characters, %s for strings).
	Each format specifier has its own rules for extracting and formatting data.


## Printing output:
	printf builds the output string based on the format specifiers and arguments.
	It sends the formatted string to the standard output (usually the console).


## Handling modifiers and flags:
	Format specifiers can have optional modifiers and flags (e.g., %04d to print integers with zero-padding).
	Modifiers affect the width, precision, and other formatting options.

## Error handling:
	printf handles various error cases, such as mismatched format specifiers and arguments.
	It returns the number of characters written (excluding the null-terminator) or a negative value on error.
