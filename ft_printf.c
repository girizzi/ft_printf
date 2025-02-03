/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:17:51 by girizzi           #+#    #+#             */
/*   Updated: 2025/02/03 18:55:44 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), format == 'X');
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_format(args, format[i + 1]);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
