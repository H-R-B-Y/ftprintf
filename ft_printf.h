/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:11:55 by hbreeze           #+#    #+#             */
/*   Updated: 2024/09/13 21:10:33 by hbreeze          ###   ########.fr       */
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
int		test_flag(t_conv *c, t_escflags flag);
void	set_flag(t_conv *c, t_escflags flag);
void	unset_flag(t_conv *c, t_escflags flag);

// conv_factory.c
t_conv	*generate_conversion(char *str, void *value);
void	delete_conversion(t_conv *c);
size_t	printed_length(t_conv *c);
void	print_conversion(t_conv *c);

// conversion_functions.c
char	*int_to_str(int *v);
char	*uint_to_str(unsigned int *v);
char	*hex_to_str(unsigned int *v);
char	*ptr_to_hex(void *ptr);

// flag_functions.c
t_conv	*padding(t_conv *c);
t_conv	*set_prefix(t_conv *c);
t_conv	*set_conversion_flags(t_conv *c);
t_conv	*correct_flags(t_conv *c);

// ft_printf.c
int		ft_printf(const char *str, ...);

// general_functions.c
void	destroy(void *ptr);
void	to_upper_wrapper(unsigned int x, char *c);
char	*str_join_and_free(char *s1, char *s2, unsigned int t);
void	*zeroit(void *ptr, size_t n);
char	*create_padding(t_conv *c);
void	substr_atoi(char *str, size_t *value);

// handle_escape.c
char	*pop_escaped_str(char **str);
t_conv	*parse_width(t_conv *c, va_list args);
t_conv	*parse_precision(t_conv *c, va_list args);

// string_precision.c
t_conv	*prepend_precision(t_conv *c);
t_conv	*truncate_precision(t_conv *c);
t_conv	*generate_output(t_conv *c);

#endif