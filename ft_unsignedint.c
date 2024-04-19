/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:48:07 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/19 14:52:01 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*unsigned int	ft_unsignedint(unsigned int n)
{
	int	result;

	result = 0;
	if (n >= 10)
	{
		result += ft_unsignedint(n / 10);
		if (result == 1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_putchar((n + '0')) == -1)
			return (-1);
		result++;
	}
	return (result);
}*/

unsigned int	ft_unsignedint(unsigned int n)
{
	unsigned int	result;

	result = 0;
	if (n >= 10)
	{
		result += ft_unsignedint(n / 10);
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	result++;
	return (result);
}
