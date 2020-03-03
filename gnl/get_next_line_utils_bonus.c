/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:44:24 by lramos-r          #+#    #+#             */
/*   Updated: 2020/02/11 18:46:03 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *t)
{
	int i;

	i = 0;
	while (t[i] != '\0')
		i++;
	return (i);
}

char		*ft_strchr(const char *str, int ch)
{
	while (*str && *str != (char)ch)
		str++;
	if (*str == (char)ch)
		return ((char *)str);
	return (NULL);
}

void		*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	p = (char *)malloc(count * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		p[i] = '\0';
		i++;
	}
	return ((void *)p);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	sub = (char *)malloc((len + 1) * (sizeof(char)));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < start && s[i])
		i++;
	j = 0;
	while (j < len && s[i])
	{
		sub[j] = s[i];
		j++;
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

char		*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		len;

	len = 0;
	while (s[len])
		len++;
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
