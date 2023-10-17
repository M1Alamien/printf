#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define UNUSED(x) (void) (x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1
/**
 * struct fmt - struct
 * @fmt: format
 * @fn: function
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt fmt_t - struct op
 * @fmt: format
 * @fn: function
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_prnt(const char *fmt, int *i, va_list prnt,
	       	char buff[], int flags, int width, int prec, int size);

int prnt_ch(va_list types, char buff[], int flags,
	       	int width, int prec, int size);
int prnt_s(va_list types, char buff[], int flags,
	       	int width, int prec, int size);
int prnt_pc(va_list types, char buff[], int flags,
	       	int width, int prec, int size);
int prnt_bi(va_list types, char buff[], int flags,
	       	int width, int prec, int size);
int prnt_int(va_list types, char buff[], int flags,
	       	int width, int prec, int size);
int prnt_uns(va_list types, char buff[], int flags,
	       	int width, int prec, int size);
int prnt_octal(va_list types, char buff[], int flags,
	       	int width, int prec, int size);
int prnt_hex(va_list types, char buff[], int flags,
	       	int width, int prec, int size);
int prnt_hexa(va_list types, char buff[], int flags,
	       	int width, int prec, int size);
int prnt_hexu(va_list types, char buff[], int flags,
	       	int width, int prec, int size);
int prnt_non(va_list types, char buff[], int flags,
	       	int width, int prec, int size);
int prnt_p(va_list types, char buff[], int flags,
	       	int width, int prec, int size);
int prnt_rev(va_list types, char buff[], int flags,
	       	int width, int prec, int size);
int prnt_rot13(va_list types, char buff[], int flags,
		int width, int prec, int size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list prnt);
int get_prec(const char *format, int *i, va_list prnt);
int get_size(const char *format, int *i);
int hwc(char c, char buff[], int flags,
		int width, int prec, int size);
int write_num(int is_positive, int i, char buff[],
		int flags, int width, int prec, int size);
int write_p(char buff[], int i, int len, int width,
		int flags, char sp, char, c2, int sp_st);
int write_uns(int isminus, int i, char buff[], int flags,
		int width, int prec, int size);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int , int);
long int convert_size_uns(unsigned long int, int);
#endif
