/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:26:27 by vambassa          #+#    #+#             */
/*   Updated: 2021/10/24 14:24:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_initialise_params(t_struct *params)
{
	params->type = 0;
	return (params);
}

int	ft_printf(const char *format, ...)
{
	t_struct	*params;
	int			count;
	int			i;

	i = -1;
	count = 0;
	params = (t_struct *) malloc(sizeof(t_struct));
	if (!params)
		return (-1);
	ft_initialise_params(params);
	va_start(params->arguments, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			params->type = format[++i];
			count += ft_print_conversion(params);
		}
		else
			count += write(1, &format[i], 1);
	}
	va_end(params->arguments);
	free(params);
	return (count);
}
