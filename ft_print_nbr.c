/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:53:33 by girizzi           #+#    #+#             */
/*   Updated: 2025/02/05 16:27:14 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function prints a number (base 10).

#include "ft_printf.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_print_nbr(int n)
{
	int	count;

	count = ft_numlen(n);
	if (n == -2147483648)
	{
		ft_print_str("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
		ft_print_nbr(n / 10);
	ft_print_char(n % 10 + '0');
	return (count);
}
