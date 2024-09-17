/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:11:55 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/17 16:49:04 by hbreeze          ###   ########.fr       */
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
	hsh_f		= (1 << 0),
	qot_f		= (1 << 1),
	zro_f		= (1 << 2),
	min_f		= (1 << 3),
	dot_f		= (1 << 4),
	spc_f		= (1 << 5),
	add_f		= (1 << 6),
	len_f		= (1 << 7)
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
int		test_flag(unsigned int flags, t_escflags flag);
void	set_flag(unsigned int *flags, t_escflags flag);
void	unset_flag(unsigned int *flags, t_escflags flag);
t_conv	*set_conversion_flags(t_conv *c);
t_conv	*correct_flags(t_conv *c);

// conv_factory.c
t_conv	*generate_conversion(char *str, void *value);
void	delete_conversion(t_conv *c);
size_t	printed_length(t_conv *c);
void	print_conversion(t_conv *c);

// conversion_functions.c
char	*int_to_str(int *v);
char	*uint_to_str(unsigned int *v);
char	*uint_to_hex(unsigned int *v);
char	*ptr_to_hex(void *ptr);

// flag_functions.c
t_conv	*set_padding(t_conv *c);
t_conv	*set_prefix(t_conv *c);

// ft_printf.c
int		ft_printf(const char *str, ...);

// general_functions.c
void	to_upper_wrapper(unsigned int x, char *c);
char	*str_join_and_free(char *s1, char *s2, unsigned int flag);
void	*zeroit(void *ptr, size_t n);
char	*create_padding(t_conv *c);
void	substr_atoi(char *str, size_t *value);

// handle_escape.c

// Str dupes the escaped string
char	*pop_escaped_str(char **str);

// Parse the width from the escaped string.
t_conv	*parse_width(t_conv *c, va_list args);

// Parse the precision value from the escape string
t_conv	*parse_precision(t_conv *c, va_list args);

// string_precision.c

// When precision is present for numeric conversion
// pad the conversion output with zeros if needed.
t_conv	*prepend_precision(t_conv *c);

// When precision is populated for a string conversion,
// truncate the string if needed.
t_conv	*truncate_precision(t_conv *c);

// Generate the output string for a given (populated) t_conv
t_conv	*generate_output(t_conv *c);

void	*pop_args(va_list args, char s);
void	*malloc_arg(va_list args, char s);

#endif