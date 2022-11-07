/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:41:49 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/04 14:00:36 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

bool	ft_isspawn(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

bool	check_unclosedwall(t_map *map, int j, char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == ' ')
		{
			if ((s[i + 1] && s[i + 1] == '0') || (s[i - 1] && s[i - 1] == '0')
				|| (i < (int)ft_strlen(map->map[j + 1])
					&& map->map[j + 1][i] == '0')
				|| (i < (int)ft_strlen(map->map[j - 1])
					&& map->map[j - 1][i] == '0'))
				return (false);
		}
	}
	return (true);
}

static short	check_validity_map(t_map *map)
{
	int	i;
	int	spawn;
	int	j;

	i = 0;
	spawn = -1;
	while (map->map[i])
	{
		j = check_line(map->map[i], i, map, &spawn);
		if (j < 1)
			return (j);
		i ++;
	}
	if (spawn == -1)
		return (-1);
	return (1);
}

static bool	check_rgb(t_colors *color)
{
	if (color->r < 0 || color->g < 0 || color->b < 0)
		return (false);
	else if (color->r > 255 || color->g > 255 || color->b > 255)
		return (false);
	return (true);
}

bool	check_params(t_cubed **cubed)
{
	int	i;

	if (!check_rgb((*cubed)->ceiling) || !check_rgb((*cubed)->floor))
	{
		ft_putstr_fd("Error\nThe RGB code is unvalid. (0 - 255)", 2);
		return (false);
	}
	i = check_validity_map((*cubed)->map);
	if (i == -1)
	{
		ft_putstr_fd("Error\nThere is a problem with the spawn point.\n", 2);
		return (false);
	}
	else if (i == -2)
	{
		ft_putstr_fd("Error\nUnrecognized param in the Map.\n", 2);
		return (false);
	}
	if (i == 0)
	{
		ft_putstr_fd("Error\nSeem to be a problem with an unclosed wall.\n", 2);
		return (false);
	}
	return (true);
}
