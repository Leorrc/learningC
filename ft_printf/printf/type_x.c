/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:36:04 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/09 20:06:18 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*precision_x(char *src, t_fields *f)
{
	char	*p;
	int		len;

	len = (int)ft_strlen(src);
	if (f->precision < len)
		p = ft_strdup(src);
	else
	{
		p = ft_strnew(f->precision);
		if (src[0] == '-')
		{
			p[0] = '-';
			ft_memset(&p[1], '0', f->precision - len + 1);
			ft_memmove(&p[f->precision - len + 2], &src[1], len);
		}
		else
		{
			ft_memset(p, '0', f->precision - len);
			ft_memmove(&p[f->precision - len], src, len);
		}
	}
	return (p);
}

char	*width_x(char *src, t_fields *f)
{
	char	*w;
	int		len;

	len = ft_strlen(src);
	if (f->width <= len)
		w = ft_strdup(src);
	else
	{
		w = ft_strnew(f->width);
		if (f->flag == '-')
		{
			ft_memmove(w, src, len);
			ft_memset(&w[len], ' ', f->width - len);
		}
		else if (f->flag == '0')
		{
			ft_memset(w, '0', f->width - len);
			ft_memmove(&w[f->width - len], src, len);
		}
		else
		{
			ft_memset(w, ' ', f->width - len);
			ft_memmove(&w[f->width - len], src, len);
		}
	}
	return (w);
}

int		type_x(t_fields *f, unsigned int arg)
{
	char	*x;
	char	*p;
	char	*w;

	x = ft_itoa_base(arg, 16);
	p = precision_x(x, f);
	w = width_x(p, f);
	ft_putstr(w);
	return (0);
}
