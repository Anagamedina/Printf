/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:59:46 by anamedin          #+#    #+#             */
/*   Updated: 2024/02/29 09:37:07 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list args;
	size_t	i;
	int	total_chars;

	i = 0;
	total_chars = 0;
	va_start(args, str);
	while(str[i] != '\0')
		if(str[i] != '%')
		{
			ft_putchar(str[i]);
			total_chars++;
		}
		else
		{
			if(str[i] == 'c')
			total_chars += ft_putchar(va_arg(args, int));
			i++;
		}
	i++;
	va_end(args);
	return(total_chars);
}
int main() 
{
    ft_printf("Hello, world!\n");
    ft_printf("The value of %s is %d\n", "x", 10);
    ft_printf("The value of %s is %c\n", "z", 'A');
    return 0;
}
