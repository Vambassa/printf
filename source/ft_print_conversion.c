/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:26:02 by vambassa          #+#    #+#             */
/*   Updated: 2021/10/24 14:24:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conversion(t_struct *params)
{
	int	count;

	count = 0;
	if (params->type == 'c')
		count = ft_print_char(params);
	else if (params->type == 's')
		count = ft_print_string(params);
	else if (params->type == 'p')
		count = ft_print_pointer(params);
	else if (params->type == 'd' || params->type == 'i')
		count = ft_print_integer(params);
	else if (params->type == 'u')
		count = ft_print_unsigned_int(params);
	else if (params->type == 'x' || params->type == 'X')
		count = ft_print_hex(params);
	else if (params->type == '%')
	{
		ft_putchar_fd('%', 1);
		count += 1;
	}
	return (count);
}
