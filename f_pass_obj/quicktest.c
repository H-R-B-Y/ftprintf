/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicktest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:43:58 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/06 02:28:52 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	char *t;
	char *d = "%+050d";

	//ft_printf("Hello this is %-50.*d x cool", 10, 4);
	printf("NULL PTR with width:\n%10p\n", 0);
	printf("NULL PTR with precision:\n%.10p\n", 0);
	printf("NULL string with width:\n%10s\n", 0);
	printf("NULL string with precision:\n%.10s\n", 0);
	printf("zero with 2 precision:\n%.2d\n",0);
	printf("zero in hex with 0 precision:\n%#.0x\n",0);
	printf("Number with precision:\n%.10d\n", 5);
	printf("Number with precision and width:\n%15.10d\n", 6);
	printf("Number with precision and width and 0 flag:\n%015.10d\n", 7);
	printf("Hex without 0 and alt form:\n%#x\n", 1);
	printf("Space is present:\n% .10d\n", 10);
	printf("PTR with precision:\n%.20p\n", "Hello");
	
	fflush(stdout);
	ft_printf("\n\nTime to test mine\n\n\n");
	fflush(stdout);
	// MINE
	ft_printf("NULL PTR with width:\n%10p\n", 0);
	ft_printf("NULL PTR with precision:\n%.10p\n", 0);
	ft_printf("NULL string with width:\n%10s\n", 0);
	ft_printf("NULL string with precision:\n%.10s\n", 0);
	ft_printf("zero with 2 precision:\n%.2d\n",0);
	ft_printf("zero in hex with 0 precision:\n%#.0x\n",0);
	ft_printf("Number with precision:\n%.10d\n", 5);
	ft_printf("Number with precision and width:\n%15.10d\n", 6);
	ft_printf("Number with precision and width and 0 flag:\n%015.10d\n", 7);
	ft_printf("Hex without 0 and alt form:\n%#x\n", 1);
	ft_printf("Space is present:\n% .10d\n", 10);
	ft_printf("PTR with precision:\n%.20p\n", "Hello");

	printf("\n\n\n\n%.50s\n\n\n", "text");
}
