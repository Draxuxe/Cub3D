/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:16:22 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/02 14:40:28 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	ft_take_sprite(t_cubed *cube)
{
	int	i;
	int	j;
	int	index_sprite;

	i = 0;
	index_sprite = 0;
	while (cube->map->map[i])
	{
		j = 0;
		while (cube->map->map[i][j])
		{
			if (index_sprite == cube->map->sprites)
				return ;
			if (cube->map->map[i][j] == '2' || cube->map->map[i][j] == '3'
				|| cube->map->map[i][j] == '4' || cube->map->map[i][j] == '5')
			{
				cube->sprite[index_sprite]->x = i;
				cube->sprite[index_sprite]->y = j;
				cube->sprite[index_sprite]->c = cube->map->map[i][j];
				index_sprite++;
			}
			j++;
		}
		i++;
	}
}

static double	sqr(double x)
{
	return (x * x);
}

static void	ft_calc_order(t_cubed *cube)
{
	int			index;
	t_sprite	*tmp;

	index = 0;
	while (index < cube->map->sprites)
	{
		cube->sprite[index]->dist = sqrt((
					sqr(cube->map->pos_x - cube->sprite[index]->x)
					+ sqr(cube->map->pos_y - cube->sprite[index]->y)));
		index++;
	}
	index = 0;
	while (index + 1 < cube->map->sprites)
	{
		if (cube->sprite[index]->dist < cube->sprite[index + 1]->dist)
		{
			tmp = cube->sprite[index];
			cube->sprite[index] = cube->sprite[index + 1];
			cube->sprite[index + 1] = tmp;
			index = -1;
		}
		index ++;
	}
}

void	ft_sprite_order(t_cubed *cube)
{
	ft_take_sprite(cube);
	ft_calc_order(cube);
}
