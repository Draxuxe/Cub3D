/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:35:30 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/02 14:39:26 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	choose_sprite(t_cubed *cube, int i)
{
	char	a;

	a = cube->sprite[i]->c;
	if (a == '2')
		return (4);
	else if (a == '3')
		return (5);
	else if (a == '4')
		return (6);
	return (cube->map->piece);
}

static void	ft_init_calc(t_cubed *cube)
{
	cube->calc->sprite_x = cube->sprite[cube->calc->index]->x + 0.5
		- cube->map->pos_x;
	cube->calc->sprite_y = cube->sprite[cube->calc->index]->y
		+ 0.5 - cube->map->pos_y;
	cube->calc->inv_det = 1.0 / (cube->map->plane_x * cube->map->dir_y
			- cube->map->dir_x * cube->map->plane_y);
	cube->calc->transform_x = cube->calc->inv_det * (cube->map->dir_y
			* cube->calc->sprite_x - cube->map->dir_x * cube->calc->sprite_y);
	cube->calc->transform_y = cube->calc->inv_det * (-cube->map->plane_y
			* cube->calc->sprite_x + cube->map->plane_x * cube->calc->sprite_y);
	cube->calc->sprite_screen_x = (int)((cube->map->width / 2)
			* (1 + cube->calc->transform_x / cube->calc->transform_y));
	cube->calc->v_move_screen = (int)(0.0 / cube->calc->transform_y);
	cube->calc->sprite_height = abs((int)(cube->map->height
				/ (cube->calc->transform_y))) / 1;
	cube->calc->draw_start_y = -cube->calc->sprite_height / 2
		+ cube->map->height / 2 + cube->calc->v_move_screen;
}

static void	ft_predraw_sprite(t_cubed *cube)
{
	if (cube->calc->draw_start_y < 0)
		cube->calc->draw_start_y = 0;
	cube->calc->draw_end_y = cube->calc->sprite_height / 2 + cube->map->height
		/ 2 + cube->calc->v_move_screen;
	if (cube->calc->draw_end_y >= cube->map->height)
		cube->calc->draw_end_y = cube->map->height - 1;
	cube->calc->sprite_w = abs((int)(cube->map->height
				/ (cube->calc->transform_y))) / 1;
	cube->calc->draw_start_x = -cube->calc->sprite_w
		/ 2 + cube->calc->sprite_screen_x;
	if (cube->calc->draw_start_x < 0)
		cube->calc->draw_start_x = 0;
	cube->calc->draw_end_x = cube->calc->sprite_w / 2
		+ cube->calc->sprite_screen_x;
	if (cube->calc->draw_end_x > cube->map->width)
		cube->calc->draw_end_x = cube->map->width;
	cube->calc->stripe = cube->calc->draw_start_x;
}

static void	ft_draw_sprite(t_cubed *cube)
{
	unsigned int	color;
	int				d;
	int				s;

	d = (cube->calc->y - cube->calc->v_move_screen) * 256 - cube->map->height
		* 128 + cube->calc->sprite_height * 128;
	cube->calc->tex_y = ((d * TEXTHEIGHT) / cube->calc->sprite_height) / 256;
	s = choose_sprite(cube, cube->calc->index);
	color = cube->textures->tab[s][TEXTWIDTH * cube->calc->tex_y
		+ cube->calc->tex_x];
	if (color != 4278190080)
	{
		cube->map->buf[cube->calc->y][cube->calc->stripe] = color;
		cube->window->data[cube->calc->y * cube->map->width
			+ cube->calc->stripe]
			= cube->map->buf[cube->calc->y][cube->calc->stripe];
	}
	cube->calc->y ++;
}

void	ft_calc_sprite(t_cubed *cube)
{
	cube->calc->index = -1;
	while (++cube->calc->index < cube->map->sprites)
	{
		ft_init_calc(cube);
		ft_predraw_sprite(cube);
		while (cube->calc->stripe < cube->calc->draw_end_x)
		{
			cube->calc->tex_x = (int)(256 * (cube->calc->stripe
						- (-cube->calc->sprite_w / 2
							+ cube->calc->sprite_screen_x))
					* TEXTWIDTH / cube->calc->sprite_w) / 256;
			if (cube->calc->transform_y > 0 && cube->calc->transform_y
				< cube->map->zbuffer[cube->calc->stripe])
			{
				cube->calc->y = cube->calc->draw_start_y;
				while (cube->calc->y < cube->calc->draw_end_y)
					ft_draw_sprite(cube);
			}
			cube->calc->stripe ++;
		}
	}
}
