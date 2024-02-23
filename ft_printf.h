/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:46:16 by anamedin          #+#    #+#             */
/*   Updated: 2024/02/23 14:41:50 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

void ft_putnbr(int n);
int	ft_putchar (char c);
int	ft_printf(char const *str, ...);


# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

#endif
