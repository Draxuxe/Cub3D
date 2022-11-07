/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:10:57 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/02 10:03:39 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_dir(t_perso *perso, t_map *map, int i, int j)
{
	perso->dir_x = 0;
	perso->dir_y = 0;
	perso->plane_x = 0.0;
	perso->plane_y = 0.0;
	if (map->map[i][j] == 'N')
	{
		perso->dir_x = -1;
		perso->plane_y = 0.66;
	}
	else if (map->map[i][j] == 'S')
	{
		perso->dir_x = 1;
		perso->plane_y = -0.66;
	}
	else if (map->map[i][j] == 'E')
	{
		perso->dir_y = 1;
		perso->plane_x = 0.66;
	}
	else if (map->map[i][j] == 'W')
	{
		perso->dir_y = -1;
		perso->plane_x = -0.66;
	}
}

t_perso	*init_perso(t_cubed *cube, int i, int j)
{
	t_perso	*perso;

	perso = malloc(sizeof(t_perso));
	if (!perso)
		return (NULL);
	perso->raydir_x = 0;
	perso->raydir_y = 0;
	perso->pos_x = (i + 0.5);
	perso->pos_y = (j + 0.5);
	perso->delta_dist_x = 0;
	perso->delta_dist_y = 0;
	perso->move_speed = 0.3;
	perso->rot_speed = 0.15;
	init_dir(perso, cube->map, i, j);
	init_map(cube->map);
	cube->perso = perso;
	return (perso);
}
