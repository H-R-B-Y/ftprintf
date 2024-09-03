/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:29:30 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/03 17:31:16 by hbreeze          ###   ########.fr       */
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
	if (c->zro_f && !c->min_f)
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
	if (c->min_f)
		result = ft_strjoin(c->output, padding);
	else if (c->zro_f)
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
		else if (c->add_f && !c->spc_f) // add overrides space 
			c->prefix = ft_strdup("+");
		else if (c->spc_f)
			c->prefix = ft_strdup(" ");
	}
	if (((c->type == 'x' || c->type == 'X') && c->hsh_f) || c->type == 'p')
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
