/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:26:18 by vambassa          #+#    #+#             */
/*   Updated: 2021/10/24 14:24:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(t_struct *params)
{
	char	*s;
	char	*null_res;

	s = va_arg(params->arguments, char *);
	if (!s)
	{
		null_res = "(null)";
		ft_putstr_fd(null_res, 1);
		return ((int)ft_strlen(null_res));
	}
	ft_putstr_fd(s, 1);
	return ((int)ft_strlen(s));
}
