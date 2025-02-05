/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:55:27 by girizzi           #+#    #+#             */
/*   Updated: 2025/02/05 19:44:50 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function prints a pointer address in hexadecimal format.

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

// static void	ft_putptr(unsigned long long num)
// {
// 	if (num >= 16)
// 	{
// 		ft_putptr(num / 16);
// 		ft_putptr(num % 16);
// 	}
// 	else
// 	{
// 		if (num <= 9)
// 			ft_print_char(num + '0');
// 		else
// 			ft_print_char(num - 10 + 'a');
// 	}
// }

int	ft_print_ptr(unsigned long long ptr)
{
	int	count;

	if (!ptr)
		return (ft_print_str("(nil)"));
	count = ft_print_str("0x");
	count += ft_ptrlen(ptr);
	ft_print_ptr(ptr);
	return (count);
}
