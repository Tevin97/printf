#include "main.h"

/**
*get_specifier - finds the format func
*@s: format string
*
*Return: number of bytes printed
*/
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"c", print_int},
		{"c", print_int},
		{"c", print_string},
		{"c", print_percent},
		{"c", print_binary},
		{"c", print_octal},
		{"c", print_unsigned},
		{"c", print_hex},
		{"c", print_HEX},
		{"c", print_address},
		{"c", print_S},
		{"c", print_rev},
		{"c", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
*get_print_func - finds func
*@s: string
*@ap: argument pointer
*@params: parameter struct
*
*Return: number of bytes printed
*/
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
*get_flag - finds the flag func
*@s: format string
*@params: parameter struct
*
*Return: if flag was valid
*/
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
		i = params->plus_flag = 1;
		break;
		case '':
		i = params->space_flag = 1;
		break;
		case '#':
		i = params->hashtag_flag = 1;
		break;
		case '-':
		i = params->minus_flag = 1;
		break;
		case '0':
		i = params->zero_flag = 1;
		break;
	}
	return (i);
}

/**
*get_modifier - finds the modifier
*@s: string format
*@params: parameter struct
*
*Return: valid modifier
*/
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
		i = params->h_modifier = 1;
		break;
		case 'l':
		i = params->l_modifier = 1;
		break;
	}
	return (i);
}

/**
*get_width - gets width from string
*@s: string format
*@params: parameter struct*
*@ap: pointer argument
*
*Return: new pointer
*/
char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}