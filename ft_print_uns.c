/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:13:28 by girizzi           #+#    #+#             */
/*   Updated: 2025/02/05 19:45:30 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function prints an unsigned number (base 10).

#include "ft_printf.h"

static void	ft_put_unsigned(unsigned int n)
{
	if (n >= 10)
		ft_put_unsigned(n / 10);
	ft_print_char(n % 10 + '0');
}

static int	ft_unsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = ft_unsigned_len(n);
	ft_put_unsigned(n);
	return (count);
}
