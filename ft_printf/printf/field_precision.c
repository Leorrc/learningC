/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:55:42 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/06 21:37:52 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		field_precision(const char *format, va_list arg)
{
	int		precision;
	char	type;

	type = field_types(format);
	precision = 0;
	while (*format && *format != type)
	{
		if (!(ft_strchr(format, '.')))
		{
			precision = -1;
			break ;
		}
		else if (*format == '.')
		{
			format++;
			if (*format == '*')
			{
				precision = va_arg(arg, int);
				break ;
			}
			while (ft_isnumber(*format))
			{
				precision = precision * 10 + *format -48;
				format++;
			}
			break ;
		}
		format++;
	}
	return (precision);
}
