/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:09:13 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/10 17:36:59 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	t_fields	*f;

	va_start(arg, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format);
		else
		{
			f = calc_fields(format, arg);
			if (f->type == 's')
				type_s(f, va_arg(arg, char *));
			else if (f->type == 'c')
				type_c(f, va_arg(arg, int));
			else if (f->type == 'd' || f->type == 'i')
				type_d(f, va_arg(arg, int));
			else if (f->type == 'u')
				type_u(f, va_arg(arg, unsigned int));
			else if (f->type == 'x' || f->type == 'X')
				type_x(f, va_arg(arg, unsigned long));
			else if (f->type == 'p')
				type_p(f, va_arg(arg, unsigned long));
			else if (f->type == '%')
			{
				type_percent(f);
				format++;
			}
			while (*format != f->type)
				format++;
		}
		format++;
	}
	va_end(arg);
	return (ft_strlen(format));
}
