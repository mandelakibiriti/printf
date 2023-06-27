#include "main.h"
#include <stdio.h>

int _strcmp(char *, char *);

/**
 * print_pointer - Print a number in hexadecimal format
 * @list: Number to print
 *
 * Return: Length of the number
 **/
int print_pointer(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(list, unsigned long int), 16);

	if (!_strcmp(p_buff, "0"))
		return (print("(nil)"));

	size = print("0x");

	if (!_strcmp(p_buff, "-1"))
		size += print("ffffffffffffffff");
	else
		size += print(p_buff);

	return (size);
}

/**
 * _strcmp - Compare two strings
 * @s1: String 1
 * @s2: String 2
 * Return: Integer
 **/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}


/**
 * print_unsigned - Print a unsigned int
 * @list: Number to print
 *
 * Return: Length of the number
 **/
int print_unsigned(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(list, unsigned int), 10);

	size = print((p_buff != NULL) ? p_buff : "NULL");

	return (size);
}

/**
 * print_string - Print string
 * @list: list.
 *
 * Return: String length.
 */

int print_string(va_list list)
{
	char *p;
	int p_len;

	p = va_arg(list, char*);
	p_len = print((p != NULL) ? p : "(null)");

	return (p_len);
}

/**
 * rot13 - Encodes a string using rot13.
 * @s: String to enconde
 * Return: String encode
 */
int rot13(char *s)
{
	int i, j;
	char *normal, *rot13;

	normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; normal[j] != '\0'; j++)
		{
			if (s[i] == normal[j])
			{
				_putchar(rot13[j]);
				break;
			}
		}

		if (!normal[j])
			_putchar(s[i]);
	}
	return (i);
}

/**
 * print_rot - Prints the rot13'ed string
 * @list: String to encoded
 *
 * Return: Length of the string encoded
 **/
int print_rot(va_list list)
{
	char *p;
	int p_len;

	p = va_arg(list, char *);
	p_len = rot13((p != NULL) ? p : "(ahyy)");

	return (p_len);
}

/**
 * print_rev_string - Print a string in reverse
 * @list: List of arguments
 *
 * Return: Length of the string
 **/
int  print_rev_string(va_list list)
{
	int i, size;
	const char *str;

	str = va_arg(list, const char *);

	size = _strlen(str);

	for (i = size - 1; i >= 0; i--)
		_putchar(str[i]);

	return (size);
}

/**
 * print_octal - Print a unsigned octal
 * @list: Number to print
 *
 * Return: Length of the number
 **/
int print_octal(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(list, unsigned int), 8);

	size = print((p_buff != NULL) ? p_buff : "NULL");

	return (size);
}

/**
 * print_integer - Print a number in base 10
 * @list: Number to print in base 10
 *
 * Return: Length of th numbers in decimal
 **/
int print_integer(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(list, int), 10);

	size = print((p_buff != NULL) ? p_buff : "NULL");

	return (size);
}

int is_lowercase(char);
char *string_to_upper(char *);

/**
 * print_hexadecimal_upp - Print a number in hexadecimal format
 * @list: Number to print
 *
 * Return: Length of the number
 **/
int print_hexadecimal_upp(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(list, unsigned int), 16);
	p_buff = string_to_upper(p_buff);

	size = print((p_buff != NULL) ? p_buff : "NULL");

	return (size);
}

/**
 * is_lowercase - Check if the character are in lowercase
 * @c: Character
 * Return: 1 or 0
 **/
int is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * string_to_upper - Change the string to uppercase
 * @s: String
 * Return: String uppercase
 **/
char *string_to_upper(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_lowercase(s[i]))
		{
			s[i] = s[i] - 32;
		}
	}

	return (s);
}

/**
 * print_hexadecimal_low - Print a number in hexadecimal format
 * @list: Number to print
 *
 * Return: Length of the number
 **/
int print_hexadecimal_low(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(list, unsigned int), 16);

	size = print((p_buff != NULL) ? p_buff : "NULL");

	return (size);
}

/**
 * print_char - print char.
 * @list: va_list.
 *
 * Return: 1
 */
int print_char(va_list list)
{
	int aux;

	aux = va_arg(list, int);

	_putchar(aux);

	return (1);
}

/**
 * print_binary - Print a number in base 2
 * @list: Number to print in base 2
 *
 * Return: Length of the numbers in binary
 **/
int print_binary(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(list, unsigned int), 2);

	size = print(p_buff);

	return (size);
}