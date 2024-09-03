/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_factory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:20:00 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/03 14:14:28 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunctions.h"

conv_t	*generate_conversion(char *str, void *value)
{
	conv_t *output;
	
	if (!str)
		return (0);
	output = malloc(sizeof(conv_t));
	output->hsh_f = 0;
	output->qot_f = 0;
	output->zro_f = 0;
	output->min_f = 0;
	output->dot_f = 0;
	output->spc_f = 0;
	output->add_f = 0;
	output->is_negative = 0;
	output->control = str;
	output->value = value;
	output->output = 0;
	output->prefix = 0;
	output->type = str[ft_strlen(str)-1];
	return (output);
}
// Control, Output, and prefix all need to be free'd!
void	delete_conversion(conv_t *c)
{
	if (!c)
		return ;
	if (c->control)
		free(c->control);
	if (c->output)
		free(c->output);
	if (c->prefix)
		free(c->prefix);
	free(c);
	return ;
}
