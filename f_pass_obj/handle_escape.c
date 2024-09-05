/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:25:06 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/05 22:00:27 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunctions.h"

char	*pop_escaped_str(char **str)
{
	char	*start;
	char	*duplicate;

	if (!str || **str != '%')
		return (0);
	start = *str;
	(*str)++;
	if (**str == '%' && (*str)++)
	{
		ft_putchar_fd('%', 1);
		return (0);
	}
	while (**str && ft_strchr("+ -0'#", **str))
		(*str)++;
	if (**str && **str != '*' && ft_strchr("123456789", **str) && (*str)++)
		while (**str && ft_strchr("0123456789", **str))
			(*str)++;
	if (**str == '*')
		(*str)++;
	if (**str && **str == '.' && (*str)++)
		while (**str && ft_strchr("0123456789", **str))
			(*str)++;
	if (*((*str)-1) == '.' && **str == '*')
		(*str)++;
	if (**str && !ft_strchr("cspdiuxX", **str))
		return (0);
	duplicate = ft_substr(start, 1, (*str - start));
	if (!duplicate)
		return (0);
	(*str)++;
	return (duplicate);
}

static void	substr_atoi(char *str, size_t *value)
{
	char *end;
	if (!str || !value)
		return ;
	if (!ft_strchr("0123456789", *str))
		return ;
	end = str;
	while (*end && ft_strchr("0123456789", *end))
		end++;
	end = ft_substr(str, 0, end - str);
	*value = (size_t)atoi(end);
	free(end);
}

conv_t	*parse_width(conv_t *c, va_list args)
{
	char *start;
	
	if (!c || !c->control)
		return (0);
	start = c->control;
	while (*start && ft_strchr("+ -0'#", *start))
		start++;
	if (!ft_strchr("123456789", *start))
		return (0);
	if (*start != '*')
		substr_atoi(start, &c->min_width);
	else
		c->min_width = va_arg(args, int);
	return (c);
}

conv_t	*parse_precision(conv_t *c, va_list args)
{
	char *start;
	
	if (!c || !c->control || !ft_strchr(c->control, '.'))
		return (0);
	start = c->control;
	while (*start && ft_strchr("+ -0'#123456789", *start))
		start++;
	if (!*start || *start != '.')
		return (0);
	set_flag(c, dot_f);
	if (*(++start) != '*')
		substr_atoi(start, &c->precision);
	else
		c-> precision = va_arg(args, int);
	return (c);
}

conv_t	*correct_flags(conv_t *c)
{
	if (!c || !c->flags)
		return (0);
	if (test_flag(c, zro_f) && c->precision)
		unset_flag(c, zro_f);
	if (test_flag(c, add_f) && test_flag(c, spc_f))
		unset_flag(c, spc_f);
	if (test_flag(c, zro_f) && test_flag(c, min_f))
		unset_flag(c, zro_f);
	if (!c->min_width)
		unset_flag(c, zro_f);
	return (c);
}

conv_t	*set_conversion_flags(conv_t *c)
{
	char *str_i;
	
	if (!c || !(c->control))
		return (0);
	str_i = c->control;
	while (*str_i && ft_strchr("+ -0'#", *str_i))
	{
		if (*str_i == '+')
			set_flag(c, add_f);
		else if (*str_i == ' ')
			set_flag(c, spc_f);
		else if (*str_i == '-')
			set_flag(c, min_f);
		else if (*str_i == '0')
			set_flag(c, zro_f);
		else if (*str_i =='\'')
			set_flag(c, qot_f);
		else if (*str_i == '#')
			set_flag(c, hsh_f);
		str_i++;
	}
	return (c);
}

// conv_t *print_escaped_argument(conv_t *c)
// {
// 	char *str;
	


// 	// int:
// 	// check if it is negative and set flag
// 	// convert to ascii (remove the minus sign if needed)
// 	// PRECISION SHOULD GO HERE?
// 	// pad:
// 	// 		RTL > 0 
// 	// signage:
// 	// 		"+" > " "
// 	// reapply minus sign

// 	// int functions:
// 	// 	itoa
// 	// 	padding
// 	// 	apply_sign

// 	// hex:
// 	// check if it is negative and set flag
// 	// convert to ascii (remove minus sign)
// 	// PRECISION SHOULD GO HERE?
// 	// pad:
// 	// 		RTL > 0
// 	// check for "#" flag and apply alt
// 	// signage:
// 	// 		"+" > " "
// 	// reapply minus sign

// 	// hex functions:
// 	// itoh
// 	// padding
// 	// apply_sign

// 	// str:
// 	// pad:
// 	// 		RTL > 0
// 	// print

// 	// void ptr
// 	// not sure here lol

// 	if (c->type == 'd' || c->type == 'i')
// 		str = "int";
// 	else if (c->type == 'x' || c->type == 'X')
// 		str = "hex";
// 	else if (c->type == 's' || c->type == 'c')
// 		str = "str";
// 	else if (c->type == 'p')
// 		str = "ptr";
// 	ft_putstr_fd(str, 1);
// 	return (c);
// }
