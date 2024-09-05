/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:29:30 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/06 02:19:33 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	*padding(t_conv *c)
{
	char	*padding;
	char	*result;

	if (!c || !c->min_width
		|| ft_strlen(c->output) + ft_strlen(c->prefix) >= c->min_width
	)
		return (c);
	padding = create_padding(c);
	if (test_flag(c, min_f))
		result = str_join_and_free(c->output, padding, (1 << 1) | (1 << 2));
	else if (test_flag(c, zro_f))
		result = str_join_and_free(padding, c->output, (1 << 1) | (1 << 2));
	else
	{
		result = str_join_and_free(padding, c->prefix, (1 << 1) | (1 << 2));
		c->prefix = result;
		return (c);
	}
	c->output = result;
	return (c);
}

t_conv	*set_prefix(t_conv *c)
{
	c->prefix = ft_strdup("");
	if (c->value == 0)
		return (c);
	if (((ft_strchr("Xx", c->type) && test_flag(c, hsh_f))
			&& *((int *)c->value) != 0)
		|| c->type == 'p'
	)
		c->prefix = str_join_and_free(c->prefix, "0x", (1 << 1));
	if (!ft_strchr("dixXp", c->type))
		return (c);
	if (c->is_negative)
		c->prefix = str_join_and_free(c->prefix, "-", (1 << 1));
	else if (test_flag(c, add_f) && !test_flag(c, spc_f))
		c->prefix = str_join_and_free(c->prefix, "+", (1 << 1));
	else if (test_flag(c, spc_f))
		c->prefix = str_join_and_free(c->prefix, " ", (1 << 1));
	return (c);
}

t_conv	*set_conversion_flags(t_conv *c)
{
	char	*str_i;

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
		else if (*str_i == '\'')
			set_flag(c, qot_f);
		else if (*str_i == '#')
			set_flag(c, hsh_f);
		str_i++;
	}
	return (c);
}

t_conv	*correct_flags(t_conv *c)
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
