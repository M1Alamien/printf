#include "main.h"
/**
 * is_printable - name
 * @c: char from main
 *
 * checks if c is printable
 * Return: 0 or 1
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * append_hexa_code - name
 * @ascii_code: char
 * @buff: char
 * @i: int
 *
 * append_hexa_code
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buff[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buff[i++] = '\\';
	buff[i++] = 'x';
	buff[i++] = map_to[ascii_code / 16];
	buff[i++] = map_to[ascii_code % 16];
	return (3);
}
/**
 * is_digit - name
 * @c: char
 *
 * checks if c is digit
 * Return: 0 or 1
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * convert_size_number - name
 * @li: int
 * @size: size
 *
 * convert_size_number
 * Return: li
 */
long int convert_size_number(long int li, int size)
{
	if (size == S_LONG)
		return (li);
	else if (size == S_SHORT)
		return ((short)li);
	return ((int)li);
}
/**
 * convert_size_uns - name
 * @uli: int
 * @size: size
 *
 * convert_size_uns
 * Return: uli
 */
long int convert_size_uns(unsigned long int uli, int size)
{
	if (size == S_LONG)
		return (uli);
	else if (size == S_SHORT)
		return ((unsigned short)uli);
	return ((unsigned int)uli);
}
