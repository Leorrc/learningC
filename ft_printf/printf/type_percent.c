/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:00:14 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/10 17:49:54 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		type_percent(t_fields *f)
{
	char	*w;

	w = ft_strnew(1);
	if (f->width > 1)
	{
		w = ft_strnew(f->width);
		if (f->flag == '-')
		{
			w[0] = '%';
			ft_memset(&w[1], ' ', f->width - 1);
		}
		else if (f->flag == '0')
		{
			ft_memset(w, '0', f->width - 1);
			w[f->width - 1] = '%';
		}
		else
		{
			ft_memset(w, ' ', f->width - 1);
			w[f->width - 1] = '%';
		}
	}
	else
		w[0] = '%';
	ft_putstr(w);
	return (0);
}
