/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:10:34 by lramos-r          #+#    #+#             */
/*   Updated: 2020/02/11 16:54:03 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <stddef.h>
# include <limits.h>
# include <fcntl.h>

int			get_next_line_bonus(int fd, char **line);
size_t		ft_strlen(const char *t);
char		*ft_strchr(const char *str, int ch);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
