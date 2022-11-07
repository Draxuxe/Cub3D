/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:20:27 by lfilloux          #+#    #+#             */
/*   Updated: 2022/10/26 11:21:16 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static size_t	size_map(char **map)
{
	int		start;
	size_t	i;

	start = findstart(map);
	i = 1;
	while (map[start] && map[start][0] != '\n')
	{
		i ++;
		start ++;
	}
	return (i);
}

static t_map	*getmap(char **rawmap, int start)
{
	t_map	*map;
	char	*tmp;
	size_t	i;
	size_t	size;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	size = size_map(rawmap);
	map->map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (rawmap[start] && i != size)
	{
		tmp = ft_strdup(rawmap[start]);
		map->map[i] = ft_strtrim(tmp, "\n");
		free(tmp);
		start ++;
		i ++;
	}
	map->map[i] = NULL;
	map->height = i;
	map->width = findx(map);
	return (map);
}

static bool	endmap(char **map)
{
	int	start_map;
	int	error;

	start_map = findstart(map);
	error = 0;
	while (map[start_map])
	{
		if (!ft_isdigit(map[start_map][0])
			&& map[start_map][0] != '\n' && map[start_map][0] != ' ')
			error = 2;
		else if ((error == 0 && map[start_map][0] == '\n')
			|| (error == 1 && map[start_map][0] != '\n'))
			error ++;
		if (error >= 2)
		{
			ft_putstr_fd("Error\nThere is something after the Map.\n", 2);
			return (false);
		}
		start_map ++;
	}
	return (true);
}

static int	getmaplines(char **map)
{
	int	start_map;
	int	c;

	start_map = findstart(map);
	c = findline(map, "C", 1);
	if (start_map < 0)
	{
		ft_putstr_fd("Error\nThe Map is missing.\n", 2);
		return (false);
	}
	else if (c > start_map)
	{
		ft_putstr_fd("Error\nThe Map is in the wrong place.\n", 2);
		return (false);
	}
	return (start_map);
}

bool	parse_map(t_cubed **cubed)
{
	if (!getmaplines((*cubed)->rawmap) || !endmap((*cubed)->rawmap))
		return (false);
	(*cubed)->map = getmap((*cubed)->rawmap, getmaplines((*cubed)->rawmap));
	if ((*cubed)->map->width < 3 || (*cubed)->map->height < 3)
	{
		ft_putstr_fd("Error\nMap too small, can't work with it.\n", 2);
		return (false);
	}
	return (true);
}
