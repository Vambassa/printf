/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:26:06 by vambassa          #+#    #+#             */
/*   Updated: 2021/10/24 14:24:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_len(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		count++;
		nbr /= 16;
	}
	return (count);
}

static void	ft_hex_conversion(unsigned int nbr, t_struct *params)
{
	if (nbr > 15)
	{
		ft_hex_conversion(nbr / 16, params);
		ft_hex_conversion(nbr % 16, params);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', 1);
		else
		{
			if (params->type == 'x')
				ft_putchar_fd(nbr - 10 + 'a', 1);
			else
				ft_putchar_fd(nbr - 10 + 'A', 1);
		}
	}
	return ;
}

int	ft_print_hex(t_struct *params)
{
	unsigned int	nbr;

	nbr = (unsigned int)va_arg(params->arguments, int);
	ft_hex_conversion(nbr, params);
	return (ft_check_len(nbr));
}
