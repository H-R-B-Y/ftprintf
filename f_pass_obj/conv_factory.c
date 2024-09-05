/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_factory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:20:00 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/06 02:27:25 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_signed_value(void *value)
{
	if (!value)
		return (0);
	else if (*((int *)value) < 0)
		return (1);
	else
		return (0);
}

t_conv	*generate_conversion(char *str, void *value)
{
	t_conv	*output;

	if (!str)
		return (0);
	output = malloc(sizeof(t_conv));
	output->flags = non_f;
	output->control = str;
	output->value = value;
	output->output = 0;
	output->prefix = 0;
	output->type = str[ft_strlen(str)-1];
	if (ft_strchr("xXdi", output->type))
		output->is_negative = check_signed_value(value);
	else
		output->is_negative = 0;
	output->min_width = 0;
	output->precision = 0;
	return (output);
}

// Control, Output, and prefix all need to be free'd!
void	delete_conversion(t_conv *c)
{
	if (!c)
		return ;
	if (ft_strchr("dixXc", c->type))
		free(c->value);
	if (c->control)
		free(c->control);
	if (c->output)
		free(c->output);
	if (c->prefix)
		free(c->prefix);
	free(c);
	return ;
}
