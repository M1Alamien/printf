#include "main.h"

int hwc(char c, char buff[], int flags, int width,
		int prec, int size)
{
	int i = 0;
	char pp = ' ';

	UNUSED(prec);
	UNUSED(size);

	if(flags & F_ZERO)
		pp = '0';

	buff[i++] = c;
	buff[i++] = '\0';
	if (width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buff[BUFF_SIZE - i - 2] = pp;

		if (flags & F_MINUS)
			return (write(1, &buff[0], 1) + write(1, &buff[BUFF_SIZE - i - 1], width - 1));
		else
			return
