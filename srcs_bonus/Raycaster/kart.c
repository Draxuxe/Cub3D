/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kart.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:03:10 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/03 10:44:04 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	ft_print_kart( t_cubed *cube)
{
	time_t	end;

	end = time(NULL);
	if (((int)difftime(end, cube->map->time_) % 2) == 0)
	{
		cube->map->kart = mlx_xpm_file_to_image(cube->window->mlx,
				"textures/kart.xpm", &cube->map->k_w, &cube->map->k_h);
		mlx_put_image_to_window(cube->window->mlx, cube->window->mlx_win,
			cube->map->kart,
			(cube->map->height - 256), (cube->map->width / 2 - 128));
	}
	else
	{
		cube->map->kart = mlx_xpm_file_to_image(cube->window->mlx,
				"textures/kart_down.xpm", &cube->map->k_w, &cube->map->k_h);
		mlx_put_image_to_window(cube->window->mlx, cube->window->mlx_win,
			cube->map->kart,
			(cube->map->height - 256), (cube->map->width / 2 - 128));
	}
}

void	ft_kart(t_cubed *cube)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if ((time.tv_sec * 1000 + time.tv_usec / 1000)
		- cube->map->tsv > 500)
	{
		cube->map->k_lright = 0;
		cube->map->k_lleft = 0;
	}
	if (cube->map->k_lright == 1)
		cube->map->kart = mlx_xpm_file_to_image(cube->window->mlx,
				"textures/look_right.xpm",
				&cube->map->k_w, &cube->map->k_h);
	else if (cube->map->k_lleft == 1)
		cube->map->kart = mlx_xpm_file_to_image(cube->window->mlx,
				"textures/look_left.xpm", &cube->map->k_w, &cube->map->k_h);
	else if (cube->map->k_rear == 1)
		cube->map->kart = mlx_xpm_file_to_image(cube->window->mlx,
				"textures/kart_rear.xpm", &cube->map->k_w, &cube->map->k_h);
	else
		ft_print_kart(cube);
	mlx_put_image_to_window(cube->window->mlx, cube->window->mlx_win,
		cube->map->kart,
		(cube->map->height - 256), (cube->map->width / 2 - 128));
}
