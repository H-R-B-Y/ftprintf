/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:13:47 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/01 17:29:12 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "helperfunctions.h"

char *dupe_escaped(char **str)
{
	char *start;
	char *duplicate;

	if (!str || **str != '%')
		return (0);
	start = *str;
	(*str)++;
	while (**str && ft_strchr("+ .-0'#", **str))
		(*str)++;
	if (**str && ft_strchr("123456789", **str) && (*str)++)
		while (**str && ft_strchr("123456789", **str))
			(*str)++;
	if (**str && !ft_strchr("cspdiuxX", **str))
		return (0);
	duplicate = ft_substr(start, 1, (*str - start));
	if (!duplicate)
		return (0);
	(*str)++;
	return (duplicate);
}

int get_flags(char *esc)
{
	int output;
	
	if (!esc)
		return (0);
	output = 0;
	if (*esc &&ft_strchr("+ .-0'#", *esc))
	{
		output += 2;
		while (ft_strchr("+ .-0'#", *esc))
			esc++;
	}
	if (*esc && ft_strchr("123456789", *esc))
	{
		output += 3;
		while (ft_strchr("0123456789", *esc))
			esc++;
	}
	return (output);
}

char *get_printable(char *esc, va_list args)
{
	char t;
	char *output;

	t = esc[ft_strlen(esc) - 1];
	if (t == 'd' || t == 'i')
		output = ft_itoa(va_arg(args, int));
	else if (t == 'x' || t == 'X')
		output = ft_itoa(va_arg(args, int));
	else if (t == 'u')
		output = ft_itoa(va_arg(args, unsigned int)); // need another itoa func to handle this.
	else if (t == 'c')
		output = ft_strdup(va_arg(args, char));
	else if (t == 's')
		output = ft_strdup(va_arg(args, char *));
	else
		output = ft_strdup("HEX VOID POINTER HERE");
	return (output);
}

#include <stdio.h>
int main ()
{
	char *str = "%..00++86786765X  hello world  ";
	printf("%s\n", dupe_escaped(&str));
	printf("%s\n", str);
}