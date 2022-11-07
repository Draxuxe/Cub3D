/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:30:01 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/02 10:11:00 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static size_t	size_map(int fd)
{
	size_t	size;
	char	*buff;

	if (fd < 0)
	{
		ft_putstr_fd("Error\nThis Map doesn't exist.\n", 2);
		exit (EXIT_FAILURE);
	}
	size = 1;
	buff = malloc(sizeof(char) * (1));
	if (!buff)
		return (0);
	while (read(fd, buff, 1))
	{
		if (buff[0] == '\n')
		size ++;
	}
	free(buff);
	return (size);
}

void	read_map(t_cubed *cubed, char *arg)
{
	int		fd;
	size_t	size;
	size_t	i;

	fd = open(arg, O_RDONLY);
	size = size_map(fd);
	cubed->rawmap = malloc(sizeof(char *) * (size + 1));
	if (!cubed->rawmap || fd < 0)
	{
		close (fd);
		return ;
	}
	fd = open(arg, O_RDONLY);
	i = 0;
	while (i != size)
	{
		cubed->rawmap[i] = get_next_line(fd);
		i ++;
	}
	cubed->rawmap[i] = NULL;
	close(fd);
}
