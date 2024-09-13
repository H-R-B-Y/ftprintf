/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_factory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:20:00 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/13 16:59:17 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

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
	if (ft_strchr("di", output->type))
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
	// Value is not always a malloc'd value!
	// This may need to be updated if anything else gets malloc'd
	if (ft_strchr("dixXcu", c->type))
		destroy(c->value);
	if (c->control)
		destroy(c->control);
	if (c->output)
		destroy(c->output);
	if (c->prefix)
		destroy(c->prefix);
	destroy(c);
	return ;
}

size_t	printed_length(t_conv *c)
{
	size_t	output;
	
	output = ft_strlen(c->prefix) + ft_strlen(c->output);
	if (!output && c->type == 'c')
		output = 1;
	return (output);
}

void	print_conversion(t_conv *c)
{
	ft_putstr_fd(c->prefix, 1);
	ft_putstr_fd(c->output, 1);
	if (*c->output == '\0' && c->type == 'c')
		write(1, "\0", 1);
}
