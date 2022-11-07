/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:18:49 by aleferra          #+#    #+#             */
/*   Updated: 2022/10/24 16:03:06 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_front(t_cubed *cube)
{
	double	x;
	double	y;

	x = get_move_x(cube);
	y = get_move_y(cube);
	if (cube->map->map[(int)(cube->perso->pos_x + x)]
		[(int)cube->perso->pos_y] == '0')
		cube->perso->pos_x += cube->perso->dir_x * cube->perso->move_speed;
	if (cube->map->map[(int)cube->perso->pos_x]
		[(int)(cube->perso->pos_y + y)] == '0')
		cube->perso->pos_y += cube->perso->dir_y * cube->perso->move_speed;
}

void	move_down(t_cubed *cube)
{
	double	x;
	double	y;

	x = get_move_x(cube);
	y = get_move_y(cube);
	if (cube->map->map[(int)(cube->perso->pos_x - x)]
		[(int)cube->perso->pos_y] == '0')
		cube->perso->pos_x -= cube->perso->dir_x * cube->perso->move_speed;
	if (cube->map->map[(int)cube->perso->pos_x]
		[(int)(cube->perso->pos_y - y)] == '0')
		cube->perso->pos_y -= cube->perso->dir_y * cube->perso->move_speed;
}

void	move_left(t_cubed *cube)
{
	double	x;
	double	y;

	x = get_move_x(cube);
	y = get_move_y(cube);
	if (cube->map->map[(int)cube->perso->pos_x]
		[(int)(cube->perso->pos_y + x)] == '0' && (cube->map->map
		[(int)(cube->perso->pos_x - y)][(int)cube->perso->pos_y] == '0'))
	{
		cube->perso->pos_y += cube->perso->dir_x * cube->perso->move_speed;
		cube->perso->pos_x -= cube->perso->dir_y * cube->perso->move_speed;
	}
}

void	move_right(t_cubed *cube)
{
	double	x;
	double	y;

	x = get_move_x(cube);
	y = get_move_y(cube);
	if (cube->map->map[(int)cube->perso->pos_x]
		[(int)(cube->perso->pos_y - x)] == '0' && (cube->map->map
		[(int)(cube->perso->pos_x + y)][(int)cube->perso->pos_y] == '0'))
	{
		cube->perso->pos_y -= cube->perso->dir_x * cube->perso->move_speed;
		cube->perso->pos_x += cube->perso->dir_y * cube->perso->move_speed;
	}
}
