/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:48:07 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/19 21:34:29 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_unsigned_rec(unsigned int n)
{
	unsigned int	result;
	unsigned int	write_return;

	result = 0;
	if (n >= 10)
	{
		write_return = ft_unsigned_rec(n / 10);
		if (write_return == 1)
			return (1);
		result += write_return;
	}
	write_return = ft_putchar((n % 10) + '0');
	if (write_return == 1)
		return (1);
	result += write_return;
	return (result);
}

unsigned int ft_unsignedint( int n)
{
	unsigned int count;
	int write_return;

	count = 0;
    if (n < 0)
	{
		n = -n; // Convert negative number to its positive equivalent
		write_return = ft_putchar('-'); // Print '-' sign for negative numbers
		if (write_return == 1)
			return (1);
		count += write_return;
	}
	write_return = ft_unsigned_rec((unsigned int)n);
    if (write_return == 1)
        return (1);
    count += write_return;
    return (count);
}
