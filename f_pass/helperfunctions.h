/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunctions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:11:55 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/01 20:07:33 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERFUNCTIONS_H
# define HELPERFUNCTIONS_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

// Using ints here is not the best approach, bit flags would be a better approach.
typedef struct conv_s
{
	short hsh_f;
	short qot_f;
	short zro_f;
	short min_f;
	short dot_f;
	short spc_f;
	short add_f;
	char *control;
	ssize_t min_width;
	char *output;
}	conv_t



#endif