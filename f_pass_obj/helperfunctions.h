/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunctions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:11:55 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/05 14:23:43 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERFUNCTIONS_H
# define HELPERFUNCTIONS_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>


typedef enum
{
	non_f		= 0,
	hsh_f		= (1 << 1),
	qot_f		= (1 << 2),
	zro_f		= (1 << 3),
	min_f		= (1 << 4),
	dot_f		= (1 << 5),
	spc_f		= (1 << 6),
	add_f		= (1 << 7)
}	escflags_t;


// Using ints here is not the best approach, bit flags would be a better approach.
//	Min width	- minimum required width of the string overidden if length of prefix + output is greater
//	Precision	- minimum width of the conversion (will pad int conversions with 0's ignores the 0 flag)
//	flags		- DUH flags
//	is_negative	- set {remind me where this is set lol} this is because itoa will include the "-" sign, but this should instead be appended to the prefix.
//	type		- char repr of the type of conversion.
//	value		- void ptr to the argument that was parsed.
//	control		- The escaped substring
//	prefix		- prefix of output string (i.e. "      +" when width and + specified)
//	output		- the result of the conversion (i.e. "00000010" whih precision)
typedef struct conv_s
{
	size_t		min_width;
	size_t		precision;

	unsigned	flags;
	
	int			is_negative;
	
	char		type;

	void		*value;
	char		*control;
	
	char		*prefix;
	char		*output;
	
}				conv_t;

// Working with flags:

// Set a flag.
void	set_flag(conv_t *c, escflags_t flag);

// Remove a flag.
void	unset_flag(conv_t *c, escflags_t flag);

// Check if flag is set.
int		test_flag(conv_t *c, escflags_t flag);


// WARN: The following is the implementation without precision being accounted for.
// NOTE: ARG may be used for either width precision modifier!

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

// Returns: the conversion struct
conv_t	*parse_precision(conv_t *c);

conv_t	*padding(conv_t *c);
conv_t	*set_prefix(conv_t *c);

// Do something here
char	*int_to_str(int *v);
char	*int_to_hex(int *v);
char	*ptr_to_hex(unsigned long *v);

conv_t	*generate_output(conv_t *c);

#endif