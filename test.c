/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:33:52 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/02 19:53:50 by hbreeze          ###   ########.fr       */
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
			
		}
		else
			count += ++last_flag;
		str++;
	}
	return (count);
}
// to prove va list can be passed to a function
// va_arg is a "pop like" function, very cool!
void test (va_list l, char *type)
{
	if (*type == 's')
		printf("%s", va_arg(l, char *));
	else if (*type == 'd')
		printf("%d", va_arg(l, int));
}



void ft_printf(char *str, ...)
{
	va_list args;
	size_t size;
	size_t index;

	if (!str)
		return ;
	index = 0;
	size = escape_count(str);
	va_start(args, str);
	while (*str)
	{
		if (!(*str == '%'))https://is2.4chan.org/gif/1724770986299372.webm
			else
				test(args, str+1);
			str++;
		}
		*str++;
	}
	return;
}

int main()
{
	ft_printf("%d %d %d %d %d %d %s \n", 65, 66, 67, 8, 9, 10, "Hello World!");
}

// So i am thinking for printf, seek through the string:
// while (*str)
//		...
//		...
// until it encounters a % sign
// then pass the va_list and the index of the percent sign onto a function
// said function will enumerate through the next few characters to identify flags/size/type
// said function will then call the corresponding function(s) to print said argument.
// said function will return the ptr to the type char
//
// This sequence will print seqentially char by char until done, meaning validation will \
//	have to occur before the printing starts:
// so like this:

// def printf (char *str, ...):
// 	if (!*str || !validate(str)):
// 		return ;
// 	size = count_params(str);
// 	va_start(arglist, str)
// 	while *str:
// 		if (*str != '%'):
// 			putchar(*str)
// 		else:
// 			str = handle_arg(arglist, *str)
// 		str++;