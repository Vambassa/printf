/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:26:21 by vambassa          #+#    #+#             */
/*   Updated: 2021/10/24 14:24:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uintlen(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

static void	ft_putuint_fd(unsigned int nbr, int fd)
{
	if (nbr / 10)
		ft_putuint_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}

int	ft_print_unsigned_int(t_struct *params)
{
	unsigned int	nbr;

	nbr = (unsigned int)va_arg(params->arguments, int);
	ft_putuint_fd(nbr, 1);
	return (ft_uintlen(nbr));
}
