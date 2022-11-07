/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:18:49 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/02 10:07:18 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

double	get_move_x(t_cubed *cube)
{
	double	x;

	if (cube->map->dir_x >= 0)
		x = (cube->map->dir_x * cube->map->move_speed) + 0.2;
	else
		x = (cube->map->dir_x * cube->map->move_speed) - 0.2;
	return (x);
}

double	get_move_y(t_cubed *cube)
{
	double	y;

	if (cube->map->dir_y <= 0)
		y = (cube->map->dir_y * cube->map->move_speed) - 0.2;
	else
		y = (cube->map->dir_y * cube->map->move_speed) + 0.2;
	return (y);
}

int	ft_key_press(int key_code, t_cubed *cube)
{
	if (key_code == KEY_ESC)
		ft_exit(cube);
	else if (cube->map->map[(int)cube->map->pos_x]
		[(int)cube->map->pos_y] == '4' && cube->map->pieces == 0)
		return (1);
	else if (key_code == KEY_E)
		ft_key_e(cube);
	else if (key_code == KEY_RIGHT)
		look_right(cube);
	else if (key_code == KEY_LEFT)
		look_left(cube);
	else if (key_code == KEY_FRONT)
		move_front(cube);
	else if (key_code == KEY_BACK)
		move_down(cube);
	return (1);
}
