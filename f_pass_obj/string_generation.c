/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_generation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:42:27 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/03 18:43:39 by hbreeze          ###   ########.fr       */
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

char *ptr_to_hex(unsigned long *ptr)
{
	*ptr = 0;
	return (0);
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
		c->output = ft_strdup(c->value);
	return (c);
}
