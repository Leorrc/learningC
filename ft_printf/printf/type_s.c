/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:23:42 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/06 21:39:37 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		type_s(t_fields *f, char *arg)
{
	int		len;
	char	*s;

	len = (int)ft_strlen(arg);
	s = ft_strdup(arg);
	if (f->precision)
	{
		if (f->precision == 0)
			s = ft_strnew(1);
		else if (len > f->precision)
			s = ft_substr(arg, 0, f->precision);
	}
	len = (int)ft_strlen(s);
	if (len >= f->width)
	{
		ft_putstr(s);
		return (0);
	}
	f->width = f->width - len;
	if (f->flag == '-')
	{
		ft_putstr(s);
		while (f->width > 0)
		{
			ft_putchar(' ');
			f->width--;
		}
	}
	else if (f->flag == '0')
		return (-1);
	else
	{
		while (f->width > 0)
		{
			ft_putchar(' ');
			f->width--;
		}
		ft_putstr(s);
	}
	return (0);
}
