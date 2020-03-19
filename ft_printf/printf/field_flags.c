/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:23:03 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/13 15:27:04 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	field_flags(const char *format)
{
	char	flag;

	flag = 0;
  if (format[1] == '0' && format[0] == '%')
    flag = '0';
	if (ft_strchr(format, '-'))
		flag = '-';
	return (flag);
}
