/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:59:46 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/17 03:19:21 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conver(const char *str, va_list args)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*str == 's')
		count += ft_print_string(va_arg(args, char *));
	else if (*str == 'p')
	{
		if (ft_print_string("0x") == -1)
			return (-1);
		count += 2;
		count += ft_hex(va_arg(args, unsigned long), (char *)&str);
	}
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	i;
	int		total_chars;
	char	*ptr;

	i = 0;
	total_chars = 0;
	va_start(args, str);
	ptr = (char *)str;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
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
	return (total_chars);
}

int	main(void)
{
	ft_printf("char: %c\n", 'a');
	printf("ORIGINAL --> char: %c\n", 'a');
	// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
	ft_printf("str: %s\n", "Ana");
	printf("ORIGINAL --> str: %s\n", "Ana");
	// ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
	//ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
	ft_printf("ptr %p", 0x1345204);
	printf("ORIGINAL --> ptr %p", 0x1345204);
	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
}
