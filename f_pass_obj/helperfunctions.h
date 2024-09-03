/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunctions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:11:55 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/03 17:26:43 by hbreeze          ###   ########.fr       */
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
	size_t	min_width;
	short	hsh_f;
	short	qot_f;
	short	zro_f;
	short	min_f;
	short	dot_f;
	short	spc_f;
	short	add_f;
	short	is_negative;
	char	type;
	char	*prefix;
	char	*control;
	char	*output;
	void	*value;
}			conv_t;

// The order of functions:
// 	pop_escaped_str
// 	generate_conversion


// 	set_conversion_flags
// 	parse_width
// 	generate_output
// 	set_prefix
// 	padding

// 	combine !!!!! where is this????

// 	print!
// 
// 	delete_conversion

// Returns: Null if malloc failed, else
// 	a new conv_t struct will null all flags set to 0
// 	str will populate the control string
conv_t	*generate_conversion(char *str, void *value);

// Returns: Nothing lol
void	delete_conversion(conv_t *c);

// Returns: a malloc'd copy of the escaped string from
// 	a formated string. str must point to the address 
// 	of the escape character. str will be fast forwarded to
// 	the end of the escaped string.
char	*pop_escaped_str(char **str);

// Returns: the conversion struct
conv_t	*set_conversion_flags(conv_t *c);

// Returns: the conversion struct
conv_t	*parse_width(conv_t *c);


conv_t	*padding(conv_t *c);
conv_t	*set_prefix(conv_t *c);

// Do something here
char *int_to_str(int *v);
char *int_to_hex(int *v);
char *ptr_to_hex(unsigned long *v);

conv_t *generate_output(conv_t *c);

#endif