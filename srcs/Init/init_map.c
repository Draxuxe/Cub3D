/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:26:33 by lfilloux          #+#    #+#             */
/*   Updated: 2022/10/24 14:54:06 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_map(t_map *map)
{
	map->time = 0;
	map->oldtime = 0;
	map->hit = 0;
	map->side = 0;
	map->width_map = map->width;
	map->height_map = map->height;
}
