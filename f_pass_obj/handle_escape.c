/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:25:06 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/02 20:28:01 by hbreeze          ###   ########.fr       */
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
	if (**str == '%')
	{
		(*str)++;
		ft_putchar_fd('%', 1);
		return (0);
	}
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

conv_t	*set_conversion_flags(conv_t *c)
{
	char *str_i;
	
	if (!c || !(c->control))
		return (0);
	str_i = c->control;
	while (*str_i && ft_strchr("+ .-0'#", *str_i))
	{
		if (*str_i == '+')
			c->add_f = 1;
		else if (*str_i == ' ')
			c->spc_f = 1;
		else if (*str_i == '.')
			c->dot_f = 1;
		else if (*str_i == '-')
			c->min_f = 1;
		else if (*str_i == '0')
			c->zro_f = 1;
		else if (*str_i =='\'')
			c->qot_f = 1;
		else if (*str_i == '#')
			c->hsh_f = 1;
		str_i++;
	}
	return (c);
}

conv_t *parse_width(conv_t *c)
{
	char *start;
	char *end;
	char *dupe;
	
	if (!c || !c->control)
		return (0);
	start = c->control;
	while (*start && ft_strchr("+ .-0'#", *start))
		start++;
	if (!ft_strchr("123456789", *start))
		return (0);
	end = start;
	while (*end && ft_strchr("123456789", *end))
		end++;
	dupe = ft_substr(start, 0, (end - start) - 1);
	c->min_width = ft_atoi(dupe);
	free(dupe);
	return (c);
}

conv_t *print_escaped_argument(conv_t *c)
{
	char *str;
	


	// int:
	// check if it is negative and set flag
	// convert to ascii (remove the minus sign if needed)
	// PRECISION SHOULD GO HERE?
	// pad:
	// 		RTL > 0 
	// signage:
	// 		"+" > " "
	// reapply minus sign

	// int functions:
	// 	itoa
	// 	padding
	// 	apply_sign

	// hex:
	// check if it is negative and set flag
	// convert to ascii (remove minus sign)
	// PRECISION SHOULD GO HERE?
	// pad:
	// 		RTL > 0
	// check for "#" flag and apply alt
	// signage:
	// 		"+" > " "
	// reapply minus sign

	// hex functions:
	// itoh
	// padding
	// apply_sign

	// str:
	// pad:
	// 		RTL > 0
	// print

	// void ptr
	// not sure here lol

	if (c->type == 'd' || c->type == 'i')
		str = "int";
	else if (c->type == 'x' || c->type == 'X')
		str = "hex";
	else if (c->type == 's' || c->type == 'c')
		str = "str";
	else if (c->type == 'p')
		str = "ptr";
	ft_putstr_fd(str, 1);
}
