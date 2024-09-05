/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:42:27 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/06 02:19:33 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	*prepend_precision(t_conv *c)
{
	size_t	pad_count;
	char	*padding;

	if (!c || !c->output)
		return (0);
	if (c->precision == 0 && !ft_strncmp(c->output, "0", 1))
	{
		free(c->output);
		c->output = ft_strdup("");
		return (c);
	}
	if (ft_strlen(c->output) >= c->precision || ft_strchr("s", c->type)
		|| (c->value == 0 && 'p' == c->type)
	)
		return (c);
	pad_count = c->precision - ft_strlen(c->output);
	padding = malloc(pad_count + 1);
	padding[pad_count] = '\0';
	ft_memset(padding, '0', pad_count);
	c->output = str_join_and_free(padding, c->output, (1 << 1) | (1 << 2));
	return (c);
}

t_conv	*generate_output(t_conv *c)
{
	if (!c)
		return (0);
	else if (c->type == 'd' || c->type == 'i')
		c->output = int_to_str(c->value);
	else if (c->type == 'x' || c->type == 'X')
		c->output = int_to_hex(c->value);
	else if (c->type == 'p')
		c->output = ptr_to_hex(c->value);
	else if (c->type == 'c')
	{
		c->output = malloc(2);
		c->output[1] = '\0';
		c->output[0] = *(char *)(c->value);
	}
	else if (c->type == 's')
	{
		c->output = ft_strdup(c->value);
		if (c->output == 0 || *c->output == '\0')
			c->output = ft_strdup("(null)");
	}
	if (ft_strchr("diuxXp", c->type))
		prepend_precision(c);
	return (c);
}
