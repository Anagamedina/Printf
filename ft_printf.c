/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:59:46 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/17 14:43:15 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conver(char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		count += ft_print_string(va_arg(args, char *));
	else if (*format == 'p')
	{
		if (ft_print_string("0x") == -1)
			return (-1);
		count += 2;
		count += ft_hex(va_arg(args, unsigned long), count);
	}
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count += ft_unsignedint(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_hex(va_arg(args, unsigned int), count);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	i;
	int		total_chars;
	char	*ptr;

	i = 0;
	total_chars = 0;
	va_start(args, format);
	ptr = (char *)format;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
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

int main(void)
{
    ft_printf("char: %c\n", 'a');
    printf("ORIGINAL --> char: %c\n", 'a');

    ft_printf("str: %s\n", "Ana");
    printf("ORIGINAL --> str: %s\n", "Ana");

    ft_printf("myprintf str  %p\n", (void *)0x1345204);
    printf("ORIGINAL --> ptr %p\n", (void *)0x1345204);

    ft_printf("Myprintfd --> digit: %d\n", -3407);
    printf("ORIGINAL --> digit: %d\n", -3407);

    ft_printf("Myprintfi --> int: %i\n", 204);
    printf("ORIGINAL --> int: %i\n", 204);

    ft_printf("Myprintfuint --> uint: %u\n", 24230);
    printf("ORIGINAL --> uint: %u\n", 24230);

    ft_printf("Myprintf --> hex: %x\n", 2423333);
    printf("ORIGINAL --> hex: %x\n", 2423333);

    return 0;
}
