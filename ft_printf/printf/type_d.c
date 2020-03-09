/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:00:45 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/09 17:59:28 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*precision_d(char *prec, t_fields *f)
{
	char	*p;
	int		len;

	len = (int)ft_strlen(prec);
	if (f->precision < len)
		p = ft_strdup(prec);
	else
	{
		if (prec[0] == '-')
		{
			p = ft_strnew(f->precision);
			p[0] = '-';
			ft_memset(&p[1], '0', f->precision - len + 1);
			ft_memmove(&p[f->precision - len + 2], &prec[1], len);
		}
		else
		{
			p = ft_strnew(f->precision);
			ft_memset(p, '0', f->precision - len);
			ft_memmove(&p[f->precision - len], prec, len);
		}
	}
	return (p);
}

char	*width_d(char *d, t_fields *f)
{
	char	*w;
	int		len;
	
	len = (int)ft_strlen(d);
	if (f->width <= len)
		w = ft_strdup(d);
	else
	{
		if (f->flag == '-')
		{
			w = ft_strnew(f->width);
			ft_memmove(w, d, len);
			ft_memset(&w[len], ' ', f->width - len);
		}
		else
		{	
			w = ft_strnew(f->width);
			ft_memset(w, ' ', f->width - len);
			ft_memmove(&w[f->width - len], d, len);
		}
	}
	return (w);
}

int		type_d(t_fields *f, int arg)
{
	char	*d;
	char	*w;
	char	*p;

	d = ft_itoa_base(arg, 10);
	p = precision_d(d, f);
	w = width_d(p, f);
	ft_putstr(w);
	return (0);
}
