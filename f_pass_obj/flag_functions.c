/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:29:30 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/05 14:24:42 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunctions.h"

static char *create_padding(conv_t *c)
{
	char *padding;
	size_t pad_count;

	pad_count = c->min_width - (ft_strlen(c->output) + ft_strlen(c->prefix));
	if (!pad_count)
		return ft_strdup("");
	padding = malloc(pad_count + 1);
	if (!padding)
		return ft_strdup("");
	padding[pad_count] = '\0';
	if (test_flag(c, zro_f) && !test_flag(c, min_f))
		ft_memset(padding, '0', pad_count);
	else
		ft_memset(padding, ' ', pad_count);
	return padding;
}

conv_t *padding(conv_t *c)
{
	char *padding;
	char *result;
	if (!c || !c->min_width || ft_strlen(c->output) + ft_strlen(c->prefix) >= c->min_width)
		return (c);
	padding = create_padding(c);
	if (test_flag(c, min_f))
		result = ft_strjoin(c->output, padding);
	else if (test_flag(c, zro_f))
		result = ft_strjoin(padding, c->output);
	else 
	{
		result = ft_strjoin(padding, c->prefix);
		free(c->prefix);
		free(padding);
		c->prefix = result;
		return (c);
	}
	free(padding);
	free(c->output);
	c->output = result;
	return (c);
}

conv_t *set_prefix(conv_t *c)
{
	char *tmp;

	if (ft_strchr("dixXp", c->type))
	{
		if (c->is_negative)
			c->prefix = ft_strdup("-");
		else if (test_flag(c, add_f) && !test_flag(c, spc_f)) // add overrides space 
			c->prefix = ft_strdup("+");
		else if (test_flag(c, spc_f))
			c->prefix = ft_strdup(" ");
	}
	if (((ft_strchr("Xx", c->type) && test_flag(c, hsh_f)) && *((int *)c->value) != 0) || c->type == 'p' )
	{
		if (c->prefix)
		{
			tmp = ft_strjoin(c->prefix, "0x");
			free(c->prefix);
			c->prefix = tmp;
		}
		else
			c->prefix = ft_strdup("0x");
	}
	if (!c->prefix)
		c->prefix = ft_strdup("");
	return (c);
}
