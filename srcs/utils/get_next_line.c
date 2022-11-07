/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:49:10 by lfilloux          #+#    #+#             */
/*   Updated: 2022/10/20 11:42:35 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_gnl_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i ++;
	}
	return (-1);
}

static char	*reader(int fd)
{
	char	*buffer;
	int		readv;

	buffer = (char *)malloc(sizeof(char) * (101));
	if (!buffer)
		return (NULL);
	readv = read(fd, buffer, 100);
	if (readv < 0)
	{
		free (buffer);
		return (NULL);
	}
	buffer[readv] = '\0';
	return (buffer);
}

static char	*continuereading(char *save, int fd)
{
	char	*new_buffer;
	char	*dest;

	dest = reader(fd);
	if (!dest)
		return (NULL);
	if (!dest[0])
	{
		free (dest);
		return (save);
	}
	if (!save)
		return (dest);
	new_buffer = ft_strjoin(save, dest);
	free (save);
	free (dest);
	return (new_buffer);
}

static char	*findnl(char *save, char *line)
{
	char	*new_buffer;
	size_t	size_len;

	if (!save || !line)
		return (NULL);
	size_len = ft_strlen(line);
	if (size_len == ft_strlen(save))
	{
		free (save);
		return (NULL);
	}
	new_buffer = ft_substr(save, size_len, (ft_strlen(save) - size_len));
	free (save);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	size_t		lensize;

	if (fd < 0)
		return (NULL);
	line = 0;
	if (ft_gnl_strchr(save, '\n') == -1)
	{
		lensize = ft_strlen(save);
		save = continuereading(save, fd);
		if (lensize == ft_strlen(save) && save)
			line = ft_substr(save, 0, lensize);
	}
	if (!save)
		return (NULL);
	if (!line && ft_gnl_strchr(save, '\n') != -1)
		line = ft_substr(save, 0, (ft_gnl_strchr(save, '\n') + 1));
	if (line)
	{
		save = findnl(save, line);
		return (line);
	}
	return (get_next_line(fd));
}
