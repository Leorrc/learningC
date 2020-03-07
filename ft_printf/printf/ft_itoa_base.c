/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:34:42 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/06 21:34:34 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		nblen(long n, int base)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len = 2;
	}
	while (n / base > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(long i, int base)
{
	char	*result;
	char	*tab_base;
	long	len;
	long	p;

	p = nblen(i, base);
	len = p;
	tab_base = ft_strdup("0123456789abcdef");
	result = ft_strnew(len + 1);
	if (i == 0)
		result[0] = '0';
	else if (i < 0)
	{
		result[0] = '-';
		i *= -1;
	}
	while (i / base >= 0 && ((i > 0) ? (--len >= 0) : (--len > 0)))
	{
		result[len] = tab_base[i % base];
		i = i /base;
	}
	result[p] = '\0';
	return (result);
}
