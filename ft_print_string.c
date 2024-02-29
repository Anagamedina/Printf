/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:00:01 by anamedin          #+#    #+#             */
/*   Updated: 2024/02/29 11:49:46 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if(!str)
	{
		ft_print_string("(null)");
		return(-1);
	}
	while(str[i] != '\0')
	{
		if (ft_putchar(str[i]) == -1)
			return(-1);
		i++;
	}
	return(i);
}
