/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:30:51 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/03 10:50:03 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	move_front(t_cubed *cube)
{
	double	x;
	double	y;

	x = get_move_x(cube);
	y = get_move_y(cube);
	if (cube->map->map[(int)(cube->map->pos_x + x)]
		[(int)cube->map->pos_y] != '1'
		&& cube->map->map[(int)(cube->map->pos_x - x)]
		[(int)cube->map->pos_y] != '2')
		cube->map->pos_x += cube->map->dir_x * cube->map->move_speed;
	if (cube->map->map[(int)cube->map->pos_x]
		[(int)(cube->map->pos_y + y)] != '1'
		&& cube->map->map[(int)(cube->map->pos_x)]
		[(int)(cube->map->pos_y + y)] != '2')
		cube->map->pos_y += cube->map->dir_y * cube->map->move_speed;
	if (cube->map->map[(int)(cube->map->pos_x)][(int)(cube->map->pos_y)] == '5')
	{
		cube->map->map[(int)(cube->map->pos_x)][(int)(cube->map->pos_y)] = '0';
		cube->map->pieces_collected += 1;
		cube->map->move_speed += 0.025;
	}
	cube->map->k_rear = 0;
}

void	move_down(t_cubed *cube)
{
	double	x;
	double	y;

	x = get_move_x(cube);
	y = get_move_y(cube);
	if (cube->map->map[(int)(cube->map->pos_x - x)]
		[(int)cube->map->pos_y] != '1'
		&& cube->map->map[(int)(cube->map->pos_x - x)]
		[(int)cube->map->pos_y] != '2')
		cube->map->pos_x -= cube->map->dir_x * cube->map->move_speed;
	if (cube->map->map[(int)cube->map->pos_x]
		[(int)(cube->map->pos_y - y)] != '1'
		&& cube->map->map[(int)(cube->map->pos_x)]
		[(int)(cube->map->pos_y - y)] != '2')
		cube->map->pos_y -= cube->map->dir_y * cube->map->move_speed;
	if (cube->map->map[(int)(cube->map->pos_x)][(int)(cube->map->pos_y)] == '5')
	{
		cube->map->map[(int)(cube->map->pos_x)][(int)(cube->map->pos_y)] = '0';
		cube->map->pieces_collected += 1;
		cube->map->move_speed += 0.025;
	}
	cube->map->k_rear = 1;
}

void	ft_key_e(t_cubed *cube)
{
	int	posx;
	int	posy;

	posx = (int)cube->map->pos_x;
	posy = (int)cube->map->pos_y;
	if (cube->map->map[posx][posy] == '2')
		cube->map->map[posx][posy] = '3';
	else if (cube->map->map[posx + 1][posy] == '2')
		cube->map->map[posx + 1][posy] = '3';
	else if (cube->map->map[posx][posy + 1] == '2')
		cube->map->map[posx][posy + 1] = '3';
	else if (cube->map->map[posx - 1][posy] == '2')
		cube->map->map[posx - 1][posy] = '3';
	else if (cube->map->map[posx][posy - 1] == '2')
		cube->map->map[posx][posy - 1] = '3';
	else if (cube->map->map[posx + 1][posy] == '3')
		cube->map->map[posx + 1][posy] = '2';
	else if (cube->map->map[posx][posy + 1] == '3')
		cube->map->map[posx][posy + 1] = '2';
	else if (cube->map->map[posx - 1][posy] == '3')
		cube->map->map[posx - 1][posy] = '2';
	else if (cube->map->map[posx][posy - 1] == '3')
		cube->map->map[posx][posy - 1] = '2';
	else if (cube->map->map[posx][posy] == '3')
		cube->map->map[posx][posy] = '2';
}
