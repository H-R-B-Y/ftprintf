/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicktest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:43:58 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/05 14:50:42 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	char *t;
	char *d = "%+050d";

	ft_printf("Hello this is %-50.10d x cool", 10);
	// printf("Number with precision: %.10d\n", 5);
	// printf("Number with precision and width: %15.10d\n", 6);
	// printf("Number with precision and width and 0 flag: %015.10d\n", 7);
	// printf("Hex without 0 and alt form: %#x\n", 1);
	// printf("Space is ignored: % .10d\n", 10);
	// printf("PTR with precision: %.100p", "Hello");
}
