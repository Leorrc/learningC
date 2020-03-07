/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:17:42 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/06 21:39:08 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		type_c(t_fields *f, int arg)
{
	unsigned char	c;

	c = (unsigned char)arg;
	if (f->width == 0)
		ft_putchar((char)c);
	else if (f->flag == '-')
	{
		ft_putchar(c);
		while (f->width > 0)
		{
			ft_putchar(' ');
			f->width--;
		}
	}
	else
	{
		while (f->width > 0)
		{
			ft_putchar(' ');
			f->width--;
		}
		ft_putchar(c);
	}
	return (0);
}
