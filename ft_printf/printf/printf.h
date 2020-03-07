/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:37:00 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/06 21:36:22 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_fields
{
	char	flag;
	char	type;
	int		width;
	int		precision;
}	t_fields;

t_fields	*calc_fields(const char *format, va_list arg);
char		field_flags(const char *format);
int		field_precision(const char *format, va_list arg);
char	field_types(const char *format);
int		field_width(const char *format, va_list arg);
char	*ft_itoa_base(long i, int base);
void	*ft_memset(void *str, int c, size_t len);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *s);
size_t		ft_strlen(const char *t);
char	*ft_strnew(int len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isnumber(char c);
int		nblen(long n, int base);
int		type_c(t_fields *f, int arg);
int		type_s(t_fields *f, char *arg);


#endif
