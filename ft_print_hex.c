/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:09:50 by girizzi           #+#    #+#             */
/*   Updated: 2025/02/06 21:31:27 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function prints a number in hexadecimal format.

#include "ft_printf.h"

static int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 1;
	while (num >= 16)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	ft_print_hex(unsigned int num, int uppercase)
{
	const char	*base;
	int			len;

	len = ft_hex_len(num);
	if (uppercase)
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	if (num >= 16)
		ft_print_hex(num / 16, uppercase);
	ft_print_char(base[num % 16]);
	return (len);
}
