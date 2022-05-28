/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:25:50 by vambassa          #+#    #+#             */
/*   Updated: 2021/10/24 14:24:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_struct *params)
{
	char	c;
	int		count;

	count = 0;
	c = va_arg(params->arguments, int);
	ft_putchar_fd(c, 1);
	count++;
	return (count);
}
