/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:59:46 by anamedin          #+#    #+#             */
/*   Updated: 2024/02/28 20:45:57 by anamedin         ###   ########.fr       */
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
			ft_putchar_fd(str[i], 1);
			total_chars++;
		}
		else
		{
			total_chars += ft_conver_char(str[i + 1], args);
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
