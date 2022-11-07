/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:52:13 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/02 14:38:30 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

bool	ft_objs(char c)
{
	if (c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5')
		return (false);
	return (true);
}

int	findline(char **map, char *way, int length)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!ft_strncmp(map[i], way, length))
			return (i);
		i ++;
	}
	return (-1);
}

bool	findthisline(char *str, char *way, int length)
{
	if (!ft_strncmp(str, way, length))
		return (true);
	return (false);
}

int	findx(t_map *map)
{
	int		x;
	size_t	len;
	int		i;

	i = 1;
	len = ft_strlen(map->map[0]);
	x = (int)len;
	while (map->map[i])
	{
		len = ft_strlen(map->map[i]);
		if ((int)len > x)
			x = (int)len;
		i ++;
	}
	return (x);
}

int	findstart(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j ++;
		if (ft_isdigit(map[i][j]))
			return (i);
		i ++;
	}
	return (-1);
}
