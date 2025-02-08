/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:50:22 by girizzi           #+#    #+#             */
/*   Updated: 2025/02/08 18:35:28 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s) // print a string
{
	int	count;

	count = 0;
	if (!s) // if s is NULL
		return (ft_print_str("(null)")); // print "(null)"
	while (*s) // while s is not NULL
	{
		count += ft_print_char(*s); // print the character
		s++; // move to the next character
	}
	return (count);
}

int	ft_print_ptr(void *ptr) // print a pointer
{
	unsigned long	tmp; // unsigned long is a type that is guaranteed to be big enough to hold the value of a pointer
	int				count; // count the number of characters printed

	count = 0; // initialize count to 0
	if (ptr == NULL) // if ptr is NULL
	{
		write(1, "(nil)", 5); // print "(nil)"
		return (5);
	}
	tmp = (unsigned long)ptr; // cast ptr to unsigned long
	count += write(1, "0x", 2); // print "0x" and increment count by 2
	count += ft_print_hex(tmp, 0); 	// print the hexadecimal representation of tmp
	return (count);
}

int	ft_print_nbr(int n) // print an integer
{
	int	count;

	count = 0;
	if (n == -2147483648)   // if n is the smallest possible integer value
	{
		ft_print_str("-2147483648"); // print "-2147483648" as a string
		return (11);
	}
	if (n < 0) // if n is negative
	{
		ft_print_char('-'); // print a minus sign
		n = -n; // make n positive
		count++;
	}
	if (n >= 10) // if n is greater than or equal to 10
		count += ft_print_nbr(n / 10); // recursively print the digits of n

	ft_print_char(n % 10 + '0'); // print the last digit of n
	count++;

	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_print_char('0');
		return (1);
	}
	if (n >= 10) // if n is greater than or equal to 10
		count += ft_print_unsigned(n / 10); // recursively print the digits of n
	ft_print_char(n % 10 + '0'); // print the last digit of n
	count++;
	return (count);
}

int	ft_print_hex(unsigned long num, int uppercase)
{
	const char	*base; 		// base is a pointer to a constant character
	int			count;		// count the number of characters printed

	if (num == 0)
	{
		ft_print_char('0'); 
		return (1);
	}
	if (uppercase)
		base = "0123456789ABCDEF"; // if uppercase is true, use uppercase letters
	else
		base = "0123456789abcdef"; // if uppercase is false, use lowercase letters
	count = 0;
	if (num >= 16) 
		count += ft_print_hex(num / 16, uppercase); // recursively print the hexadecimal representation of num

	ft_print_char(base[num % 16]); // print the last digit of num
	count++;
	return (count);
}
