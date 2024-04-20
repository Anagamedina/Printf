/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:59:46 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/20 13:20:05 by anamedin         ###   ########.fr       */
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
		count += ft_hex(va_arg(args, unsigned long), 'p');
	}
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count += ft_unsignedint(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_hex(va_arg(args, unsigned int), 'x');
	else if (*format == 'X')
		count += ft_hex(va_arg(args, unsigned int), 'X');
	else if (*format == '%')
		count += ft_putchar('%');
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
	while (ptr[i] != '\0' && total_chars != -1)
	{
		if (ptr[i] == '%')
		{
			total_chars += ft_conver(&ptr[i + 1], args);
			i++;
		}
		else
		{
			total_chars += ft_putchar(ptr[i]);
		}
		i++;
	}
	va_end(args);
	return (total_chars);
}

/*int main() {
    printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %c - Print a single character
    ft_printf("BYANA --> %c \n", 'A');
    printf("ORIGI --> %c \n", 'A');
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %s - Print a string
    ft_printf("BYANA --> %s \n", "Hello world");
    printf("ORIGI --> %s \n", "Hello world");
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %p - Print a pointer in hexadecimal format
    char str[] = "Example";
    void *ptr = &str;
    ft_printf("BYANA --> %p \n", ptr);
    printf("ORIGI --> %p \n", ptr);
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %d - Print a decimal number (base 10)
    int num = 42;
    ft_printf("BYANA --> %d \n", num);
    printf("ORIGI --> %d \n", num);
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %i - Print an integer in base 10
    ft_printf("BYANA --> %i \n", num);
    printf("ORIGI --> %i \n", num);
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %u - Print an unsigned decimal number (base 10)
    unsigned int uns_num = 100;
    ft_printf("BYANA --> %u \n", uns_num);
    printf("ORIGI --> %u \n", uns_num);
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %x - Print a hexadecimal number in lowercase
    ft_printf("BYANA --> %x \n", num);
    printf("ORIGI --> %x \n", num);
	printf(">\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %X - Print a hexadecimal number in uppercase
    ft_printf("BYANA --> %X \n", num);
    printf("ORIGI --> %X \n", num);
	printf("> \n -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

    // %% - Print the percentage symbol
    ft_printf("BYANA --> %% \n");
    printf("ORIGI --> %% \n");

    printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
    return 0;
}*/
