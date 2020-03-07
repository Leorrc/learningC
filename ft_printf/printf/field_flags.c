/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:23:03 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/06 19:33:51 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	field_flags(const char *format)
{
	char	flag;

	flag = 0;
	format++;
	if (*format == '-' || *format == '0')
		flag = *format;
	return (flag);
}
