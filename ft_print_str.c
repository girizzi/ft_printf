/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:50:22 by girizzi           #+#    #+#             */
/*   Updated: 2025/02/05 16:24:00 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function prints a string.

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_print_str("(null)"));
	while (*s)
	{
		count += ft_print_char(*s);
		s++;
	}
	return (count);
}
