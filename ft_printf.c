/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:59:46 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/17 01:05:52 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list args;
	size_t	i;
	int	total_chars;
	char	*ptr;

	i = 0;
	total_chars = 0;
	va_start(args, str);
	ptr = (char *)str;
	while(str[i] != '\0')
	{
		if(str[i] != '%')
		{
			ft_putchar(str[i]);
			total_chars++;
		}
		else
		{
			total_chars += ft_conver(&ptr[i + 1], args);
			i++;
		}
		i++;
	}
	va_end(args);
	return(total_chars);
}
int	main()
{
	ft_printf("char: %c\n", 'a');
 	printf("ORIGINAL --> char: %c\n", 'a');

	// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
	ft_printf("str: %s\n", "Ana");
	printf("ORIGINAL --> str: %s\n", "Ana");
	// ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
}
