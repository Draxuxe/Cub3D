/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:46:13 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/07 17:28:49 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	check_special(char *s, int i, int j, t_map *map)
{
	int	diff;

	diff = 1;
	if (s[i] == ' ' && j == 0)
	{
		while (map->map[j + diff] && map->map[j + diff][i]
			&& map->map[j + diff][i] == ' ')
			diff ++;
		if (!map->map[j + diff] || !map->map[j + diff][i]
			|| (map->map[j + diff][i] && map->map[j + diff][i] != '1'))
			return (false);
	}
	else if (s[i] == ' ' && j == (map->height - 1))
	{
		while (map->map[j - diff] && map->map[j - diff][i]
			&& map->map[j - diff][i] == ' ')
			diff ++;
		if (!map->map[j - diff] || !map->map[j - diff][i]
			|| (map->map[j - diff][i] && map->map[j - diff][i] != '1'))
			return (false);
	}
	return (true);
}

static bool	check_for_lim(t_map *map, char *s, int j)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i ++;
	while (s[i] && (s[i] == '1' || s[i] == ' '))
	{
		if (!check_special(s, i, j, map))
			return (false);
		else if (s[i] != ' ' && s[i] != '1')
			return (false);
		i ++;
	}
	if (s[i] && s[i] != '1' && s[i] != ' ')
		return (false);
	return (true);
}

static bool	check_around(t_map *map, int j, char *s)
{
	int		i;
	size_t	end;

	i = 0;
	end = ft_strlen(s) - 1;
	while (s[i] && s[i] == ' ')
		i ++;
	if (i == (int)ft_strlen(s) || (s[i] && s[i] != '1'))
		return (false);
	while (s[end] && s[end] == ' ')
		end --;
	if (end == 0 || (s[end] && s[end] != '1'))
		return (false);
	return (check_unclosedwall(map, j, s));
}

static bool	check_border(t_map *map, int j)
{
	int	i;

	i = 0;
	if (j == 0 || j == (map->height - 1))
		return (check_for_lim(map, map->map[j], j));
	else if (!check_around(map, j, map->map[j])
		|| !check_walls(map, map->map[j], j))
		return (false);
	return (true);
}

int	check_line(char *s, int j, t_cubed *cube, int *spawn)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i ++;
	if (!check_border(cube->map, j))
		return (0);
	else
	{
		while (s[i])
		{
			if (!ft_isspawn(s[i]) && s[i] != '0' && s[i] != '1' && s[i] != ' ')
				return (-2);
			else if (*spawn == -1 && ft_isspawn(s[i]))
			{
				*spawn = i;
				cube->perso = init_perso(cube, j, i);
				cube->map->map[j][i] = '0';
			}
			else if (ft_isspawn(s[i]) && *spawn != -1)
				return (-1);
			i ++;
		}
	}
	return (1);
}
