/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:51:47 by lramos-r          #+#    #+#             */
/*   Updated: 2020/02/11 18:49:58 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(new = (char *)(malloc((len + 1) * sizeof(char)))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

void	ft_free_str(char **c)
{
	if (c != NULL)
	{
		free(*c);
		*c = NULL;
	}
}

int		get_error(int fd, int ret, char **line, char **str)
{
	if (fd < 0 || ret < 0 || line == NULL || BUFFER_SIZE < 1 ||
			read(fd, NULL, 0) < 0)
		return (-1);
	else if (ret == 0 && str[fd] == NULL)
	{
		*line = ft_calloc(1, 1);
		return (0);
	}
	return (1);
}

int		get_line(int ret, int fd, char **line, char **str)
{
	int		i;
	char	*x;
	int		error;

	if ((error = get_error(fd, ret, line, str)) < 1)
		return (error);
	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_substr(str[fd], 0, i);
		x = ft_strdup(&str[fd][i + 1]);
		free(str[fd]);
		str[fd] = x;
		if (str[fd][0] == '\0')
			ft_free_str(&str[fd]);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_free_str(&str[fd]);
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	char		*tmp;
	static char	*str[OPEN_MAX];
	int			ret;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	ft_free_str(&buffer);
	return (get_line(ret, fd, line, str));
}
