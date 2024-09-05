/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:36:06 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/06 02:16:22 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_to_str(int *v)
{
	char	*str;
	char	*tmp;

	str = ft_itoa(*v);
	if (!str)
		return (0);
	if (str[0] == '-')
	{
		tmp = ft_substr(str, 1, ft_strlen(str) - 1);
		free(str);
		str = tmp;
	}
	return (str);
}

static size_t	digits_needed(long long n, int base)
{
	long	digits;
	int		i;

	digits = 1;
	i = 0;
	while (digits <= n)
	{
		digits *= base;
		i++;
	}
	return (i + !(n));
}

char	*int_to_hex(int *v)
{
	char	*output;
	long	num;
	size_t	digits;

	num = (long)*v;
	if (num < 0)
		num *= -1;
	digits = digits_needed(num, 16);
	output = malloc(digits + 1);
	if (!output)
		return (0);
	output[digits--] = '\0';
	while (num / 16 > 0)
	{
		output[digits] = "0123456789abcdef"[num % 16];
		num /= 16;
		digits--;
	}
	output[digits] = "0123456789abcdef"[num % 16];
	return (output);
}

char	*ptr_to_hex(void *ptr)
{
	unsigned long	p;
	size_t			digits;
	char			*output;

	if (!ptr)
		return (ft_strdup("(nil)"));
	p = (unsigned long)ptr;
	digits = digits_needed(p, 16);
	output = malloc(digits + 1);
	if (!output)
		return (0);
	output[digits--] = '\0';
	while (p / 16 > 0)
	{
		output[digits] = "0123456789abcdef"[p % 16];
		p /= 16;
		digits--;
	}
	output[digits] = "0123456789abcdef"[p % 16];
	return (output);
}
