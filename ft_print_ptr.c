/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:55:27 by girizzi           #+#    #+#             */
/*   Updated: 2025/02/06 21:13:06 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function prints a pointer address in hexadecimal format.

#include "ft_printf.h"

void	ft_putnbr_base(uintptr_t nbr, char *base)
{
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, base);
	write(1, &base[nbr % 16], 1);
}

int	ft_print_ptr(void *ptr)
{
	int			count;
	uintptr_t	tmp;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));

	count += write(1, "0x", 2);
	ft_putnbr_base((uintptr_t)ptr, "0123456789abcdef");

	tmp = (uintptr_t)ptr;
	while (tmp > 0)
	{
		count++;
		tmp /= 16;
	}

	return (count);
}

// void	ft_add_ptr(void *ptr)
// {
// 	unsigned long	add;

// 	add = (unsigned long)ptr;
// 	write(1, "0x", 2);
// 	ft_print_hex(add, 0);
// }

// int	ft_print_ptr(void *ptr)
// {
// 	int				count;
// 	unsigned long	tmp;

// 	count = 2;
// 	tmp = (unsigned long)ptr;
// 	if (tmp == 0)
// 	{
// 		write(1, "(nil)", 5);
// 		count = 5;
// 	}
// 	else
// 	{
// 		ft_add_ptr(ptr);
// 		while (tmp > 0)
// 		{
// 			count++;
// 			tmp /= 16;
// 		}
// 	}
// 	return (count);
// }
