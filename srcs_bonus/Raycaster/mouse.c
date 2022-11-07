/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:31:53 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/03 10:50:30 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	look_left(t_cubed *cube)
{
	struct timeval	time;
	double			old_dir_x;
	double			old_plan_x;

	gettimeofday(&time, NULL);
	old_dir_x = cube->map->dir_x;
	cube->map->dir_x = cube->map->dir_x * cos(cube->map->rot_speed)
		- cube->map->dir_y * sin(cube->map->rot_speed);
	cube->map->dir_y = old_dir_x * sin(cube->map->rot_speed)
		+ cube->map->dir_y * cos(cube->map->rot_speed);
	old_plan_x = cube->map->plane_x;
	cube->map->plane_x = cube->map->plane_x * cos(cube->map->rot_speed)
		- cube->map->plane_y * sin(cube->map->rot_speed);
	cube->map->plane_y = old_plan_x * sin(cube->map->rot_speed)
		+ cube->map->plane_y * cos(cube->map->rot_speed);
	cube->map->k_lleft = 1;
	cube->map->k_lright = 0;
	cube->map->k_rear = 0;
	cube->map->tsv = time.tv_sec * 1000 + time.tv_usec / 1000;
}

void	look_right(t_cubed *cube)
{
	struct timeval	time;
	double			old_dir_x;
	double			old_plan_x;

	gettimeofday(&time, NULL);
	old_dir_x = cube->map->dir_x;
	cube->map->dir_x = cube->map->dir_x * cos(-(cube->map->rot_speed))
		- cube->map->dir_y * sin(-(cube->map->rot_speed));
	cube->map->dir_y = old_dir_x * sin(-(cube->map->rot_speed))
		+ cube->map->dir_y * cos (-(cube->map->rot_speed));
	old_plan_x = cube->map->plane_x;
	cube->map->plane_x = cube->map->plane_x * cos(-(cube->map->rot_speed))
		- cube->map->plane_y * sin(-(cube->map->rot_speed));
	cube->map->plane_y = old_plan_x * sin(-(cube->map->rot_speed))
		+ cube->map->plane_y * cos(-(cube->map->rot_speed));
	cube->map->k_lright = 1;
	cube->map->k_lleft = 0;
	cube->map->k_rear = 0;
	cube->map->tsv = time.tv_sec * 1000 + time.tv_usec / 1000;
}

static void	look_mouse(t_cubed *cube)
{
	struct timeval	time;
	int				a;
	int				b;

	gettimeofday(&time, NULL);
	mlx_mouse_get_pos(cube->window->mlx_win, &a, &b);
	if (a < (cube->map->width / 2))
		look_left(cube);
	else if (a > (cube->map->width / 2))
		look_right(cube);
	if ((cube->map->width / 2 - 1) <= a && a <= (cube->map->width / 2 + 1))
	{
		if ((time.tv_sec * 1000 + time.tv_usec / 1000)
			- cube->map->tsv > 500)
		{	
			cube->map->k_lleft = 0;
			cube->map->k_lright = 0;
			cube->map->tsv = time.tv_sec * 1000 + time.tv_usec
				/ 1000;
		}
	}
}

int	mouse_move_hook(int x, int y, t_cubed *cube)
{
	int				mx;
	int				my;
	int				a;
	int				b;
	struct timeval	time;

	gettimeofday(&time, NULL);
	mlx_mouse_get_pos(cube->window->mlx_win, &a, &b);
	if (a == (cube->map->width / 2))
	{
		if ((time.tv_sec * 1000 + time.tv_usec / 1000)
			- cube->map->tsv > 500)
		{	
			cube->map->k_lleft = 0;
			cube->map->k_lright = 0;
			cube->map->tsv = time.tv_sec * 1000 + time.tv_usec / 1000;
		}
		return (0);
	}
	mx = x - cube->map->width * 0.5;
	my = y - cube->map->height * 0.5;
	look_mouse(cube);
	mlx_mouse_move(cube->window->mlx_win, cube->map->width * 0.5,
		cube->map->height * 0.5);
	return (0);
}
