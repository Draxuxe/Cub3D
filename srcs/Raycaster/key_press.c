/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:40 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/02 10:04:42 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	look_left(t_cubed *cube)
{
	double	old_dir_x;
	double	old_plan_x;

	old_dir_x = cube->perso->dir_x;
	cube->perso->dir_x = cube->perso->dir_x * cos(cube->perso->rot_speed)
		- cube->perso->dir_y * sin(cube->perso->rot_speed);
	cube->perso->dir_y = old_dir_x * sin(cube->perso->rot_speed)
		+ cube->perso->dir_y * cos(cube->perso->rot_speed);
	old_plan_x = cube->perso->plane_x;
	cube->perso->plane_x = cube->perso->plane_x * cos(cube->perso->rot_speed)
		- cube->perso->plane_y * sin(cube->perso->rot_speed);
	cube->perso->plane_y = old_plan_x * sin(cube->perso->rot_speed)
		+ cube->perso->plane_y * cos(cube->perso->rot_speed);
}

static void	look_right(t_cubed *cube)
{
	double	old_dir_x;
	double	old_plan_x;

	old_dir_x = cube->perso->dir_x;
	cube->perso->dir_x = cube->perso->dir_x * cos(-(cube->perso->rot_speed))
		- cube->perso->dir_y * sin(-(cube->perso->rot_speed));
	cube->perso->dir_y = old_dir_x * sin(-(cube->perso->rot_speed))
		+ cube->perso->dir_y * cos (-(cube->perso->rot_speed));
	old_plan_x = cube->perso->plane_x;
	cube->perso->plane_x = cube->perso->plane_x
		* cos(-(cube->perso->rot_speed)) - cube->perso->plane_y
		* sin(-(cube->perso->rot_speed));
	cube->perso->plane_y = old_plan_x * sin(-(cube->perso->rot_speed))
		+ cube->perso->plane_y * cos(-(cube->perso->rot_speed));
}

double	get_move_x(t_cubed *cube)
{
	double	x;

	if (cube->perso->dir_x >= 0)
		x = (cube->perso->dir_x * cube->perso->move_speed) + 0.2;
	else
		x = (cube->perso->dir_x * cube->perso->move_speed) - 0.2;
	return (x);
}

double	get_move_y(t_cubed *cube)
{
	double	y;

	if (cube->perso->dir_y <= 0)
		y = (cube->perso->dir_y * cube->perso->move_speed) - 0.2;
	else
		y = (cube->perso->dir_y * cube->perso->move_speed) + 0.2;
	return (y);
}

int	ft_key_press(int key_code, t_cubed *cube)
{
	if (key_code == KEY_ESC)
		ft_exit(cube);
	else if (key_code == KEY_LOOK_RIGHT)
		look_right(cube);
	else if (key_code == KEY_LOOK_LEFT)
		look_left(cube);
	else if (key_code == KEY_FRONT)
		move_front(cube);
	else if (key_code == KEY_BACK)
		move_down(cube);
	else if (key_code == KEY_LEFT)
		move_left(cube);
	else if (key_code == KEY_RIGHT)
		move_right(cube);
	return (1);
}
