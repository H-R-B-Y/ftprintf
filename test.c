/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:33:52 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/30 16:14:39 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "PRINTMEMORY.c"
#include <stdarg.h>

size_t escape_count(char *str)
{
	size_t	count; 
	short	last_flag;

	if (!str)
		return (0);
	count = 0;
	last_flag = 0;
	while (*str)
	{
	
		if (*str == '%')
		{
			if(last_flag)
				last_flag = 0;
			else
				count += ++last_flag;
		}
		str++;
	}
	return (count);
}

void ft_printf(char *str, ...)
{
	va_list args;
	size_t count;

	if (!str)
		return ;
	count = escape_count(str);
	va_start(args, count);
	for (int i = 0; i <= count; i++)
	{
		int t = va_arg(args, int);
		ft_print_memory(&t, 16);
	}
	return;
}

int main()
{
	ft_printf("% % % % % %", 65, 66, 67, 8, 9, 10);
	printf("%\n\n\n\n");
}