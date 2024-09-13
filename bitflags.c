/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:05:49 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/11 15:09:58 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// or operator, sets the flag, if flag already set do nothing
void	set_flag(t_conv *c, t_escflags flag)
{
	c->flags |= flag;
}

void	unset_flag(t_conv *c, t_escflags flag)
// this funtion does this...
// flip bits to create bit mask, then and operate to unset
{
	c->flags &= ~(int)flag;
}

// if the and operator is equal to the test flag returns 1
int	test_flag(t_conv *c, t_escflags flag)
{
	return ((c->flags & flag) == flag);
}
