/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:08 by aleferra          #+#    #+#             */
/*   Updated: 2022/10/24 17:10:47 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_calc(t_cubed *cube)
{
	cube->perso->camera_x = 2 * cube->map->x / (double)cube->map->width - 1;
	cube->perso->raydir_x = cube->perso->dir_x
		+ cube->perso->plane_x * cube->perso->camera_x;
	cube->perso->raydir_y = cube->perso->dir_y
		+ cube->perso->plane_y * cube->perso->camera_x;
	cube->map->map_x = (int)cube->perso->pos_x;
	cube->map->map_y = (int)cube->perso->pos_y;
	cube->perso->delta_dist_x = fabs(1 / cube->perso->raydir_x);
	cube->perso->delta_dist_y = fabs(1 / cube->perso->raydir_y);
	cube->map->hit = 0;
}

void	ft_get_step(t_cubed *cube)
{
	if (cube->perso->raydir_x < 0)
	{
		cube->map->step_x = -1;
		cube->perso->side_dist_x = (cube->perso->pos_x - cube->map->map_x)
			* cube->perso->delta_dist_x;
	}
	else
	{
		cube->map->step_x = 1;
		cube->perso->side_dist_x = (cube->map->map_x + 1.0 - cube->perso->pos_x)
			* cube->perso->delta_dist_x;
	}
	if (cube->perso->raydir_y < 0)
	{
		cube->map->step_y = -1;
		cube->perso->side_dist_y = (cube->perso->pos_y - cube->map->map_y)
			* cube->perso->delta_dist_y;
	}
	else
	{
		cube->map->step_y = 1;
		cube->perso->side_dist_y = (cube->map->map_y + 1.0 - cube->perso->pos_y)
			* cube->perso->delta_dist_y;
	}
}

void	ft_collision(t_cubed *cube)
{
	while (cube->map->hit == 0)
	{
		if (cube->perso->side_dist_x < cube->perso->side_dist_y)
		{
			cube->perso->side_dist_x += cube->perso->delta_dist_x;
			cube->map->map_x += cube->map->step_x;
			cube->map->side = 0;
		}
		else
		{	
			cube->perso->side_dist_y += cube->perso->delta_dist_y;
			cube->map->map_y += cube->map->step_y;
			cube->map->side = 1;
		}
		if (cube->map->map[cube->map->map_x][cube->map->map_y] == '1')
			cube->map->hit = 1;
	}
	if (cube->map->side == 0)
		cube->perso->perp_wall_dist = (cube->map->map_x - cube->perso->pos_x
				+ (1 - cube->map->step_x) / 2) / cube->perso->raydir_x;
	else
		cube->perso->perp_wall_dist = (cube->map->map_y - cube->perso->pos_y
				+ (1 - cube->map->step_y) / 2) / cube->perso->raydir_y;
}

void	ft_draw_start_end(t_cubed *cube)
{
	cube->map->line_height = (int)(cube->map->height
			/ cube->perso->perp_wall_dist);
	cube->map->draw_start = -cube->map->line_height / 2 + cube->map->height / 2;
	if (cube->map->draw_start < 0)
		cube->map->draw_start = 0;
	cube->map->draw_end = cube->map->line_height / 2 + cube->map->height / 2;
	if (cube->map->draw_end >= cube->map->height)
		cube->map->draw_end = cube->map->height - 1;
	if (cube->map->side == 0)
		cube->map->wallx = cube->perso->pos_y
			+ cube->perso->perp_wall_dist * cube->perso->raydir_y;
	else
		cube->map->wallx = cube->perso->pos_x
			+ cube->perso->perp_wall_dist * cube->perso->raydir_x;
	cube->map->wallx -= floor(cube->map->wallx);
}

void	ft_predraw(t_cubed *cube)
{
	int		i;
	int		text_x;
	int		text_y;
	double	text_pos;

	text_x = get_text_x(cube);
	cube->map->step = 1.0 * TEXTHEIGHT / cube->map->line_height;
	text_pos = (cube->map->draw_start - cube->map->height / 2
			+ cube->map->line_height / 2) * cube->map->step;
	i = -1;
	while (++i < cube->map->height)
	{
		if (i >= cube->map->draw_start && i <= cube->map->draw_end)
		{
			text_y = (int)text_pos & (TEXTHEIGHT - 1);
			text_pos += cube->map->step;
			cube->map->buf[i][cube->map->x] = get_text(cube, text_y, text_x);
		}
		else if (i < cube->map->draw_start)
			cube->map->buf[i][cube->map->x] = cube->ceiling->rgb;
		else
			cube->map->buf[i][cube->map->x] = cube->floor->rgb;
		cube->window->data[i * cube->map->width + cube->map->x]
			= cube->map->buf[i][cube->map->x];
	}
}
