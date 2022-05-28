/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:26:13 by vambassa          #+#    #+#             */
/*   Updated: 2021/10/24 14:24:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_ptrlen(unsigned long long nbr)
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

static void	ft_ptr_hex(unsigned long long nbr)
{
	if (nbr > 15)
	{
		ft_ptr_hex(nbr / 16);
		ft_ptr_hex(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd(nbr - 10 + 'a', 1);
	}
	return ;
}

int	ft_print_pointer(t_struct *params)
{
	unsigned long long	ptr;

	ptr = (unsigned long long)va_arg(params->arguments, void *);
	ft_putstr_fd("0x", 1);
	ft_ptr_hex(ptr);
	return (ft_check_ptrlen(ptr) + 2);
}
