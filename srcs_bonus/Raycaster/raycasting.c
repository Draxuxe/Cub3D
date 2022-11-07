/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:08 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/02 14:40:24 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	ft_calc(t_cubed *cube)
{
	cube->map->camera_x = 2 * cube->map->x / (double)cube->map->width - 1;
	cube->map->raydir_x = cube->map->dir_x + cube->map->plane_x
		* cube->map->camera_x;
	cube->map->raydir_y = cube->map->dir_y + cube->map->plane_y
		* cube->map->camera_x;
	cube->map->map_x = (int)cube->map->pos_x;
	cube->map->map_y = (int)cube->map->pos_y;
	cube->map->delta_dist_x = fabs(1 / cube->map->raydir_x);
	cube->map->delta_dist_y = fabs(1 / cube->map->raydir_y);
	cube->map->hit = 0;
}

void	ft_get_step(t_cubed *cube)
{
	if (cube->map->raydir_x < 0)
	{
		cube->map->step_x = -1;
		cube->map->side_dist_x = (cube->map->pos_x - cube->map->map_x)
			* cube->map->delta_dist_x;
	}
	else
	{
		cube->map->step_x = 1;
		cube->map->side_dist_x = (cube->map->map_x + 1.0 - cube->map->pos_x)
			* cube->map->delta_dist_x;
	}
	if (cube->map->raydir_y < 0)
	{
		cube->map->step_y = -1;
		cube->map->side_dist_y = (cube->map->pos_y - cube->map->map_y)
			* cube->map->delta_dist_y;
	}
	else
	{
		cube->map->step_y = 1;
		cube->map->side_dist_y = (cube->map->map_y + 1.0 - cube->map->pos_y)
			* cube->map->delta_dist_y;
	}
}

void	ft_colision(t_cubed *cube)
{
	while (cube->map->hit == 0)
	{
		if (cube->map->side_dist_x < cube->map->side_dist_y)
		{
			cube->map->side_dist_x += cube->map->delta_dist_x;
			cube->map->map_x += cube->map->step_x;
			cube->map->side = 0;
		}
		else
		{	
			cube->map->side_dist_y += cube->map->delta_dist_y;
			cube->map->map_y += cube->map->step_y;
			cube->map->side = 1;
		}
		if (cube->map->map[cube->map->map_x][cube->map->map_y] == '1')
			cube->map->hit = 1;
	}
	if (cube->map->side == 0)
		cube->map->perp_wall_dist = (cube->map->side_dist_x
				- cube->map->delta_dist_x);
	else
		cube->map->perp_wall_dist = (cube->map->side_dist_y
				- cube->map->delta_dist_y);
}

void	ft_draw_start_end(t_cubed *cube)
{
	cube->map->line_height = (int)(cube->map->height
			/ cube->map->perp_wall_dist);
	cube->map->draw_start = -cube->map->line_height / 2 + cube->map->height / 2;
	if (cube->map->draw_start < 0)
		cube->map->draw_start = 0;
	cube->map->draw_end = cube->map->line_height / 2 + cube->map->height / 2;
	if (cube->map->draw_end >= cube->map->height)
		cube->map->draw_end = cube->map->height - 1;
	if (cube->map->side == 0)
		cube->map->wallx = cube->map->pos_y + cube->map->perp_wall_dist
			* cube->map->raydir_y;
	else
		cube->map->wallx = cube->map->pos_x + cube->map->perp_wall_dist
			* cube->map->raydir_x;
	cube->map->wallx -= floor(cube->map->wallx);
}
