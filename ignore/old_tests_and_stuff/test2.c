/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:32:45 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/31 17:30:22 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "PRINTMEMORY.c"
#include <stdarg.h>
#include "libft/libft.h"

void _my_put_hex(unsigned long int x, int index, int is_loop, char *hex)
{
	unsigned long int	overflow;

	overflow = x / 16;
	if (overflow)
	{
		_my_put_hex(overflow, 0, 1, hex);
	}
	write(1, "0", 1 * (x < 16) * !(is_loop));
	write(1, &(hex[x % 16]), 1);
	write(1, " ", 1 * (!(index % 2 == 0)));
}

void wrapper_puthex (int x, int flag_caps)
{
	_my_put_hex((unsigned long int)x, 0, 0, !flag_caps ? "0123456789abcdef" : "0123456789ABCDEF");
}

char *handle_flags(char *str, char *value, void (*f)(char *, char *))
{
	//
}

char *handle_escape(char *str, va_list args)
{
	char *start;
	if (!(str + 1))
		return (str);
	start = str++;
	while (*str && ft_strchr(". #", *str)) // flags go here
		str++;
	while (*str && ft_isdigit(*str)) // width param
		str++;
	if (*str && ft_strchr("xX", *str)) // type conversions here
		wrapper_puthex(va_arg(args, int), (*str == 'X'));
	else if (*str && ft_strchr("di", *str))
		ft_putnbr_fd(va_arg(args, int), 1);
	else
		return (0); // ERROR
	return (str);
}

void ft_printf(char *str, ...)
{
	va_list args;
	if (!str)
		return ;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str = handle_escape(str, args);
		}
		else
		{
			ft_putchar_fd(*str, 1);
		}
		str++;
	}
	va_end(args);
}

int main ()
{
	ft_printf("%d %d %d %x %x %X\n", 10, 12,13,14,15,13);
	printf("% 05ld", 6647657896);
}