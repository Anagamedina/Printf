/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:28:37 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/19 11:03:20 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		if (count == -1)
			return (-1);
		n = -n;
	}
	if (n == -2147483648)
	{
		return (ft_print_string("2147483648"));
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		if (count == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_putchar(n + '0') == -1)
			return (-1);
		count++;
	}
	return (count);
}
