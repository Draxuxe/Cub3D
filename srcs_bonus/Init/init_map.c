/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:26:33 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/02 11:03:59 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	init_dir(t_map *map, int i, int j)
{
	map->dir_x = 0;
	map->dir_y = 0;
	map->plane_x = 0.0;
	map->plane_y = 0.0;
	if (map->map[i][j] == 'N')
	{
		map->dir_x = -1;
		map->plane_y = 0.66;
	}
	else if (map->map[i][j] == 'S')
	{
		map->dir_x = 1;
		map->plane_y = -0.66;
	}
	else if (map->map[i][j] == 'E')
	{
		map->dir_y = 1;
		map->plane_x = 0.66;
	}
	else if (map->map[i][j] == 'W')
	{
		map->dir_y = -1;
		map->plane_x = -0.66;
	}
}

void	init_map(t_map *map, int i, int j)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	init_dir(map, i, j);
	map->pos_x = i + 0.5;
	map->pos_y = j + 0.5;
	map->raydir_x = 0;
	map->raydir_y = 0;
	map->delta_dist_x = 0;
	map->delta_dist_y = 0;
	map->hit = 0;
	map->side = 0;
	map->move_speed = 0.2;
	map->rot_speed = 0.1;
	map->door = 1;
	map->piece = 7;
	map->time_start = time.tv_sec * 1000 + time.tv_usec / 1000;
	map->end = 0;
	map->height_map = map->height;
	map->t = 0;
	map->oldt = 0;
}

void	ft_init_cube(t_cubed *cube)
{
	struct timeval	time;

	cube->window = malloc(sizeof(t_window));
	if (!cube->window)
		exit (EXIT_FAILURE);
	cube->start = time.tv_sec * 1000 + time.tv_usec / 1000;
	cube->map->time_start = time.tv_sec * 1000 + time.tv_usec / 1000;
	cube->calc = malloc(sizeof(t_calc));
	if (!cube->calc)
		exit (EXIT_FAILURE);
	cube->map->width = 1000;
	cube->map->height = 600;
	cube->map->zbuffer = malloc(sizeof(int *) * cube->map->width);
	if (!cube->map->zbuffer)
		exit(EXIT_FAILURE);
	cube->window->mlx = mlx_init();
	cube->map->buf = ft_lock_tab(cube);
	cube->textures->tab = ft_lock_texture();
	cube->sprite = NULL;
}
