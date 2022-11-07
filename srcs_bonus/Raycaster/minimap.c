/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:38:22 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/07 14:52:50 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	calc_fps(t_cubed *cube)
{
	struct timeval		time;
	double				frametime;

	cube->map->oldt = cube->map->t;
	cube->map->t = gettimeofday(&time, NULL);
	cube->map->t = time.tv_sec * 1000 + time.tv_usec / 1000;
	frametime = (cube->map->t - cube->map->oldt) / 10;
	cube->map->move_speed = frametime / 100 * 4
		+ cube->map->pieces_collected * 0.005;
	cube->map->rot_speed = frametime / 100 * 2.5;
	return ;
}

void	ft_mult(t_cubed *cube, int i, int j, int color)
{
	int	a;
	int	b;
	int	c;

	i *= 4;
	j *= 4;
	a = i + 4;
	c = j + 4;
	while (i <= a)
	{
		b = j;
		while (b <= c)
		{
			cube->map->buf[i + 2][b + 2] = color;
			cube->window->data[i * cube->map->width + cube->map->x]
				= cube->map->buf[i][cube->map->x];
			b++;
		}
		i++;
	}
}

void	ft_minimap(t_cubed *cube)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cube->map->height_map)
	{
		j = -1;
		while (++j < (int)ft_strlen(cube->map->map[i]))
		{
			if (i == (int)cube->map->pos_x && j == (int)cube->map->pos_y)
				ft_mult(cube, i, j, 0x0FF00EC);
			else if (cube->map->map[i][j] == '1')
				ft_mult(cube, i, j, 0x0000000);
			else if (cube->map->map[i][j] == '0')
				ft_mult(cube, i, j, 0x00FFFFFF);
			else if (cube->map->map[i][j] == '2')
				ft_mult(cube, i, j, 0x0FF0000);
			else if (cube->map->map[i][j] == '3')
				ft_mult(cube, i, j, 0x0000FF0F);
			else if (cube->map->map[i][j] == '4')
				ft_mult(cube, i, j, 0x000F7FF);
			else if (cube->map->map[i][j] == '5')
				ft_mult(cube, i, j, 0x00F1C40F);
		}
	}
}
