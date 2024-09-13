/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:43:04 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/13 21:03:26 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	destroy(void *ptr)
{
	free(ptr);
	ptr = 0;
	return ;
}

void	to_upper_wrapper(unsigned int x, char *c)
{
	(void)x;
	*c = ft_toupper(*c);
}

char	*str_join_and_free(char *s1, char *s2, unsigned int t)
{
	char	*output;

	output = ft_strjoin(s1, s2);
	if ((t & (1 << 1)) == (1 << 1))
		destroy(s1);
	if ((t & (1 << 2)) == (1 << 2))
		destroy(s2);
	return (output);
}


void	*zeroit(void *ptr, size_t n)
{
	size_t	index;

	if (!ptr)
		return (0);
	index = 0;
	while (index < n)
		((unsigned char *) ptr)[index++] = (unsigned char ) '\0';
	return (ptr);
}

char	*create_padding(t_conv *c)
{
	char	*padding;
	size_t	pad_count;

	pad_count = c->min_width - (ft_strlen(c->output) + ft_strlen(c->prefix));
	pad_count -= (c->type == 'c' && *(char *)c->value == '\0');
	if (!pad_count)
		return (ft_strdup(""));
	padding = malloc(pad_count + 1);
	if (!padding)
		return (ft_strdup(""));
	padding[pad_count] = '\0';
	if (test_flag(c, zro_f) && !test_flag(c, min_f))
		ft_memset(padding, '0', pad_count);
	else
		ft_memset(padding, ' ', pad_count);
	return (padding);
}

void	substr_atoi(char *str, size_t *value)
{
	char	*end;

	if (!str || !value)
		return ;
	if (!ft_strchr("0123456789", *str))
		return ;
	end = str;
	while (*end && ft_strchr("0123456789", *end))
		end++;
	end = ft_substr(str, 0, end - str);
	*value = (size_t)atoi(end);
	destroy(end);
}


