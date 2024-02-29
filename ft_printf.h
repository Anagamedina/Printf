/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:44:31 by anamedin          #+#    #+#             */
/*   Updated: 2024/02/29 13:34:22 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int   ft_printf(char const *str, ...);
int   ft_putchar(char c);
void  ft_putnbr(int n);
int   ft_conver(const char *str, va_list args);
int   ft_print_string(char *str);
int   ft_print_ptr()


#endif
