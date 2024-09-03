/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:29:30 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/03 14:33:40 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunctions.h"

conv_t *padding(conv_t *c)
{
	size_t pad_count;
	char *padding;
	char *result;
	if (!c || !c->min_width || ft_strlen(c->output) >= c->min_width)
		return (c);
	pad_count = c->min_width - ft_strlen(c->output);
	padding = malloc(pad_count + 1);
	if (!padding) // what the fuck do we do here?
		return (0);
	padding[pad_count] = '\0';
	if (c->zro_f && !c->min_f)
		ft_memset(padding, '0', pad_count);
	else
		ft_memset(padding, ' ', pad_count);
	if (c->min_f)
		result = ft_strjoin(c->output, padding);
	else
		result = ft_strjoin(padding, c->output);
	free(padding);
	free(c->output);
	c->output = result;
	return (c);
}


// Adove padding is wrong.
// I think we should store a "preface" variable to store things
// like " " and "+"/"-" or even "0x" for alt
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
}
