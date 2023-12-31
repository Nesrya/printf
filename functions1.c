#include "main.h"

/******* THIS PRINT UNSIGNED NUMBER ********/
/**
 * print_unsigned - this Prints an unsigned number
 * @types: this List a of arguments
 * @buffer: this one Buffer array to handle print
 * @flags: this one Calculates active flags
 * @width: this one get width
 * @precision: this one Precision specification
 * @size: this Size specifier
 * Return: a Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/******* THIS PRINT UNSIGNED NUMBER IN OCTAL  ********/
/**
 * print_octal - this one Prints an unsigned number in octal notation
 * @types: a Lista of arguments
 * @buffer: a Buffer array to handle print
 * @flags: this Calculates active flags
 * @width: to get width
 * @precision: the Precision specification
 * @size: the Size specifier
 * Return: the Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** TO PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - this Prints an unsigned number in hexadecimal notation
 * @types: a Lista of arguments
 * @buffer: to Buffer array to handle print
 * @flags: to Calculates active flags
 * @width: to get width
 * @precision: the Precision specification
 * @size: the Size specifier
 * Return: the Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* TO PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - to Print an unsigned number in upper hexadecimal notation
 * @types: a Lista of arguments
 * @buffer: a Buffer array to handle print
 * @flags: to Calculates active flags
 * @width: to get width
 * @precision: a Precision specification
 * @size: the Size specifier
 * Return: the Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** to PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - this Prints a hexadecimal number in lower or upper
 * @types: a Lista of arguments
 * @map_to:an Array of values to map the number to
 * @buffer: a Buffer array to handle print
 * @flags: to Calculates active flags
 * @flag_ch: this Calculates active flags
 * @width: to get width
 * @precision: the Precision specification
 * @size: the Size specifier
 * @size: the Size specification
 * Return: the Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
