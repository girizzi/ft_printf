/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girizzi <girizzi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:47:27 by girizzi           #+#    #+#             */
/*   Updated: 2025/02/05 16:22:52 by girizzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function prints a character.

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}
