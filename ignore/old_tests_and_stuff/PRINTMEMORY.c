/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PRINTMEMORY.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:39:09 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/30 14:18:27 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
Prints the character c, count times.
pad_x("p", 5) -> ppppp
Used to pad the spacing between the hex values in memory and their ASCII.
Also used to pad any additional 0's needed in the void* mem address.
*/
void	my_pad_x(char c, int count)
{
	int	i;

	i = 0;
	while (count > i++)
		write(1, &c, 1);
}

/*
Writes hex from x without leading 0's
x = 15 -> f; x = 16 -> 10; x = 127 -> 7f; x = 128 -> 80
Index is used by the main function to apply spaces in the correct places.
WARN: is_loop SHOULD ALWAYS BE SET TO 0 IF CALLED EXTERNALLY.
*/
void	my_put_hex(unsigned long int x, int index, int is_loop)
{
	unsigned long int	overflow;

	overflow = x / 16;
	if (overflow)
	{
		my_put_hex(overflow, 0, 1);
	}
	write(1, "0", 1 * (x < 16) * !(is_loop));
	write(1, &("0123456789abcdef"[x % 16]), 1);
	write(1, " ", 1 * (!(index % 2 == 0)));
}

/*
Prints an Unsigned long int in hex format with leading zeros.
Checks if padding zeros are needed and calls pad_x if needed.
Then calls put hex to print the remaining hex digits.
And closes with a colon and space ": "
*/
void	my_put_uintl(unsigned long int x)
{
	int					digits;
	unsigned long int	overflow;

	overflow = x / 16;
	digits = 1;
	while (overflow)
		overflow = overflow / (unsigned long)(16 + (0 * digits++));
	my_pad_x('0', 16 - digits);
	my_put_hex(x, 0, 0);
	write(1, ": ", 2);
}

/*
Put str full stop non-printable.
Reads length bytes from str, printing any ASCII bytes and printing
a full stop if ASCII is not printable.
*/
unsigned char	*put_str_fs_npr(unsigned char *str, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if ((str[i] >= ' ' && str[i] <= '~'))
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
	return (str);
}

/*
Main function to print memory.
Each row represents at most 16 bytes, so we loop (size / 16)+1 times,
We convert the address to an unsigned long int and print it.
Each loop then reads 16 bytes (except the last in which size % 16 bytes 
are read ONLY if size % 16 != 0) by casting
the void pointer to an unsigned char pointer.
Unsigned is used as reading random memory into signed chars caused some issues
when it came to printing "Negative" characters. 
The bytes are then printed and the same unsigned char pointer is then passed 
into write, to print either 16 (or in the case of the last line size % 16 bytes 
ONLY when size % 16 != 0).
*/
void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	x;
	unsigned char	*bytes;
	void			*my_addr;

	if (!addr)
		return (0);
	my_addr = addr;
	i = 0 * !(size--);
	while (size + 1 && i <= size / 16)
	{
		my_put_uintl((unsigned long int)my_addr);
		x = 0;
		while (x < 16 && !(i == size / 16 && x > size % 16))
		{
			bytes = (unsigned char *)my_addr;
			my_put_hex(bytes[x], (signed)x, 0);
			x++;
		}
		my_pad_x(' ', (i == size / 16)
			* (((16 - (size % 16)) * 2) + (16 - (size % 16)) / 2) - 2);
		put_str_fs_npr(((unsigned char *)&bytes[0]), (signed)x);
		my_addr += 16 * (1 && ++i);
	}
	return (addr);
}
