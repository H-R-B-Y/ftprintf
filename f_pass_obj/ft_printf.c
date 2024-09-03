/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:12:19 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/03 18:16:10 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunctions.h"

int validate_input_str(const char *str)
{
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			while (*str && ft_strchr("+ .-0'#", *str))
				str++;
			if (*str && ft_strchr("123456789", *str))
				while (*str && ft_strchr("1234567890", *str))
					str++;
			if (*str && !ft_strchr("cspdiuxX", *str))
				return (0);
		}
		else if (*str == '%' && !*(str+1))
			return (0);
		str++;
	}
	return (1);
}

static void *consume_arg(va_list args, char s)
{
	int *int_result;
	char *char_result;
	
	if (s == 'd' || s == 'i' || s == 'x' || s == 'X')
	{
		int_result = malloc(sizeof(int));
		*int_result = va_arg(args, int);
		return (int_result);
	}
	else if (s == 'c')
	{
		char_result = malloc(1);
		*char_result = va_arg(args, int);
		return (char_result);
	}
	else if (s == 'p')
		return (va_arg(args, void *));
	else if (s == 's')
		return (va_arg(args, char *));
	return (0);
}

int	ft_printf (const char *str, ...)
{
	va_list args;
	conv_t *conversion;
	void *val;
	char *esc;

	if (!validate_input_str(str))
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			esc = pop_escaped_str((char **)&str);
			val = consume_arg(args, (char)*(str-1));
			conversion = generate_conversion(esc, val);
			if (!conversion)
				return (-1);
			set_conversion_flags(conversion);
			parse_width(conversion);
			generate_output(conversion);
			set_prefix(conversion);
			padding(conversion);
			ft_putstr_fd(conversion->prefix, 1);
			ft_putstr_fd(conversion->output, 1);
			delete_conversion(conversion);
			continue ;
		}
		else 
			ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return (0);
}