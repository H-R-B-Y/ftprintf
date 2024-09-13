/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:25:06 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/06 02:19:33 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pop_escaped_str(char **str)
{
	char	*start;
	char	*duplicate;

	if (!str || **str != '%')
		return (0);
	start = *str;
	(*str)++;
	while (**str && ft_strchr("+ -0'#", **str))
		(*str)++;
	if (**str && ft_strchr("123456789", **str) && (*str)++)
		while (**str && ft_strchr("0123456789", **str))
			(*str)++;
	if (**str == '*')
		(*str)++;
	if (**str && **str == '.' && (*str)++)
		while (**str && ft_strchr("0123456789", **str))
			(*str)++;
	if (*((*str) - 1) == '.' && **str == '*')
		(*str)++;
	if (**str && !ft_strchr("cspdiuxX", **str))
		return (0);
	duplicate = ft_substr(start, 1, (*str - start));
	(*str)++;
	return (duplicate);
}

t_conv	*parse_width(t_conv *c, va_list args)
{
	char	*start;

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

t_conv	*parse_precision(t_conv *c, va_list args)
{
	char	*start;

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
		c->precision = va_arg(args, int);
	return (c);
}
