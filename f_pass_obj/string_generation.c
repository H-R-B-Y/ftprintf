/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_generation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:42:27 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/05 22:35:17 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunctions.h"

char *int_to_str(int *v)
{
	char *str;
	char *tmp;
	
	str = ft_itoa(*v);
	if (!str)
		return (0);
	if (str[0] == '-')
	{
		tmp = ft_substr(str, 1, ft_strlen(str) - 1);
		free(str);
		str = tmp;
	}
	return str;
}

char *int_to_hex(int *v)
{
	char *str = ft_itoa(*v);
	return str;
}

char	*ptr_to_hex(void *ptr)
{
	if (!ptr)
		return (ft_strdup("(nil)"));
	(void)ptr;
	return (ft_strdup("HEX"));
}

conv_t *prepend_precision(conv_t *c)
{
	size_t	pad_count;
	char	*padding;
	char	*temp;

	if (!c || !c->value || !c->precision || !c->output)
		return (0);
	if (ft_strlen(c->output) >= c->precision)
		return (c);
	pad_count = c->precision - ft_strlen(c->output);
	padding = malloc(pad_count + 1);
	padding[pad_count] = '\0';
	ft_memset(padding, '0', pad_count);
	temp = ft_strjoin(padding, c->output);
	free(c->output);
	free(padding);
	c->output = temp;
	return (c);
}

conv_t *generate_output(conv_t *c)
{
	if (!c || !c->value)
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
		if (c->output == 0)
	}
	if (c->precision && ft_strchr("diuxXp", c->type))
		prepend_precision(c);
	return (c);
}
