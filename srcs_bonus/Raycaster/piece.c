/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:10:35 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/02 14:40:15 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	ft_count_sprites(t_cubed *cube)
{
	int	i;
	int	y;
	int	sprites;
	int	pieces;

	i = -1;
	sprites = 0;
	pieces = 0;
	while (cube->map->map[++i])
	{
		y = 0;
		while (cube->map->map[i][y])
		{
			if (cube->map->map[i][y] != '0' && cube->map->map[i][y] != '1')
				sprites ++;
			if (cube->map->map[i][y] == '5')
				pieces ++;
			y ++;
		}
	}
	if (pieces == 0
		&& cube->map->map[(int)cube->map->pos_x][(int)cube->map->pos_y] == '4')
		cube->map->end = 1;
	cube->map->sprites = sprites;
	cube->map->pieces = pieces;
}

void	ft_piece(t_cubed *cube)
{
	struct timeval	time;
	long			side;

	gettimeofday(&time, NULL);
	side = time.tv_sec * 1000 + time.tv_usec / 1000;
	side -= cube->map->time_start;
	if (side > 100)
	{
		cube->map->time_start = time.tv_sec * 1000 + time.tv_usec / 1000;
		if (cube->map->piece == 12)
			cube->map->piece = 7;
		else
			cube->map->piece += 1;
	}
}
