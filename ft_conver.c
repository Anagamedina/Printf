/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:02:47 by anamedin          #+#    #+#             */
/*   Updated: 2024/02/29 10:59:42 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conver(const char *str, va_list args)
{
	int	count;

	count = 0;
	if(*str == 'c')
		count += ft_putchar(va_arg(args, int));
	else if(*str == 's')
		count += ft_print_string(va_arg(args, char *));
	return(count);
}
