/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:11:55 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/06 02:21:01 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef enum escflags_e
{
	non_f		= 0,
	hsh_f		= (1 << 1),
	qot_f		= (1 << 2),
	zro_f		= (1 << 3),
	min_f		= (1 << 4),
	dot_f		= (1 << 5),
	spc_f		= (1 << 6),
	add_f		= (1 << 7)
}				t_escflags;

typedef struct conv_s
{
	size_t			min_width;
	size_t			precision;
	unsigned int	flags;
	int				is_negative;
	char			type;
	void			*value;
	char			*control;
	char			*prefix;
	char			*output;
}					t_conv;

// bitflags.c
// Functions to work with flags.

// Set a flag.
void	set_flag(t_conv *c, t_escflags flag);

// Remove a flag.
void	unset_flag(t_conv *c, t_escflags flag);

// Check if flag is set.
int		test_flag(t_conv *c, t_escflags flag);

// conv_factory.c
// Functions pertaining to the creation and destruction of the conv_t

// Returns: Null if malloc failed, else
// 	a new conv_t struct will null all flags set to 0
// 	str will populate the control string
t_conv	*generate_conversion(char *str, void *value);

// Returns: Nothing lol
void	delete_conversion(t_conv *c);

// Returns: a malloc'd copy of the escaped string from
// 	a formated string. str must point to the address 
// 	of the escape character. str will be fast forwarded to
// 	the end of the escaped string.
char	*pop_escaped_str(char **str);

// Returns: the conversion struct
t_conv	*set_conversion_flags(t_conv *c);

// Returns: the conversion struct
t_conv	*parse_width(t_conv *c, va_list args);

// Returns: the conversion struct
t_conv	*parse_precision(t_conv *c, va_list args);

// Returns: the conversion struct
t_conv	*correct_flags(t_conv *c);

t_conv	*padding(t_conv *c);
t_conv	*set_prefix(t_conv *c);

// Conversion Functions.
char	*int_to_str(int *v);
char	*int_to_hex(int *v);
char	*ptr_to_hex(void *v);

t_conv	*generate_output(t_conv *c);

//general_fucntions.c
char	*create_padding(t_conv *c);
char	*str_join_and_free(char *s1, char *s2, unsigned int t);
void	substr_atoi(char *str, size_t *value);

#endif