/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:46:07 by vambassa          #+#    #+#             */
/*   Updated: 2021/10/24 14:24:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "../Libft/libft.h"

typedef struct s_struct
{
	va_list	arguments;
	char	type;
}	t_struct;

int	ft_printf(const char *format, ...);
int	ft_print_conversion(t_struct *params);
int	ft_print_char(t_struct *params);
int	ft_print_hex(t_struct *params);
int	ft_print_integer(t_struct *params);
int	ft_print_pointer(t_struct *params);
int	ft_print_string(t_struct *params);
int	ft_print_unsigned_int(t_struct *params);

#endif
