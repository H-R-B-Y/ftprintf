/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:31:52 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/02 19:54:01 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunctions.h"

char *alt_flag(char *str)
{
	char *output;
	
	output = ft_strjoin("0x", str);
	free(str);
	return (output)
}
