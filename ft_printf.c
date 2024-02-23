/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:59:46 by anamedin          #+#    #+#             */
/*   Updated: 2024/02/23 17:13:11 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list args;
	va_start(args, format);

	while(*format)
	{
		if (*format == '%')
		{
			format ++;
		}
	}
}
int main() {
    ft_printf("Hello, world!\n");
    ft_printf("The value of %s is %d\n", "x", 10);
    ft_printf("The value of %s is %f\n", "y", 3.14);
    ft_printf("The value of %s is %c\n", "z", 'A');
    return 0;
}

