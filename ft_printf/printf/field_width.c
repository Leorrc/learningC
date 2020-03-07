/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:50:46 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/06 19:55:27 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		field_width(const char *format, va_list arg)
{
	int		width;

	width = 0;
	while (*format)
	{
		if (*format == '*')
		{
			width = va_arg(arg, int);
			break;
		}
		if (isnumber(*format) && *format != '0')
		{
			while (isnumber(*format))
			{
				width = width * 10 + *format - 48;
				format++;
			}
			break;
		}
		format++;
	}
	return (width);
}
