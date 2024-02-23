/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:36:26 by anamedin          #+#    #+#             */
/*   Updated: 2024/02/23 16:36:29 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Avanzar más allá del carácter '%'

            // Manejar la conversión
            if (*format == 'c')
            {
                char c = (char)va_arg(args, int);
                putchar(c);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *s = va_arg(args, char *);
                while (*s)
                {
                    putchar(*s++);
                    printed_chars++;
                }
            }
            else if (*format == 'p')
            {
                void *p = va_arg(args, void *);
                printed_chars += printf("%p", p);
            }
            else if (*format == 'd' || *format == 'i')
            {
                int d = va_arg(args, int);
                printed_chars += printf("%d", d);
            }
            else if (*format == 'u')
            {
                unsigned int u = va_arg(args, unsigned int);
                printed_chars += printf("%u", u);
            }
            else if (*format == 'x')
            {
                unsigned int x = va_arg(args, unsigned int);
                printed_chars += printf("%x", x);
            }
            else if (*format == 'X')
            {
                unsigned int X = va_arg(args, unsigned int);
                printed_chars += printf("%X", X);
            }
            else if (*format == '%')
            {
                putchar('%');
                printed_chars++;
            }
            else
            {
                // Manejar cualquier carácter de formato no reconocido
                putchar(*format);
                printed_chars++;
            }
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }
        format++; // Avanzar al siguiente carácter en el formato
    }

    va_end(args);

    return printed_chars;
}
