/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predraw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:09:38 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/07 14:44:20 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	ft_set_text_x(t_cubed *cube)
{
	int	text_x;

	text_x = (int)(cube->map->wallx * (double)TEXTWIDTH);
	if ((cube->map->side == 0 && cube->map->raydir_x > 0)
		|| (cube->map->side == 1 && cube->map->raydir_y < 0))
		text_x = TEXTWIDTH - text_x - 1;
	return (text_x);
}

static int	color_pixel(t_cubed *cube, int text_x, int text_y)
{
	int	color;

	color = 0;
	if (cube->map->side == 1 && cube->map->step_y == 1)
		color = cube->textures->tab[3][TEXTHEIGHT * text_y + text_x];
	else if (cube->map->side == 1 && cube->map->step_y == -1)
		color = cube->textures->tab[2][TEXTHEIGHT * text_y + text_x];
	else if (cube->map->side == 0 && cube->map->step_x == 1)
		color = cube->textures->tab[1][TEXTHEIGHT * text_y + text_x];
	else if (cube->map->side == 0 && cube->map->step_x == -1)
		color = cube->textures->tab[0][TEXTHEIGHT * text_y + text_x];
	return (color);
}

void	ft_predraw(t_cubed *cube)
{
	int		i;
	int		text_x;
	int		text_y;
	double	text_pos;

	text_x = ft_set_text_x(cube);
	cube->map->step = 1.0 * TEXTHEIGHT / cube->map->line_height;
	text_pos = (cube->map->draw_start - cube->map->height
			/ 2 + cube->map->line_height / 2) * cube->map->step;
	i = -1;
	while (++i < cube->map->height)
	{
		if (i >= cube->map->draw_start && i <= cube->map->draw_end)
		{
			text_y = (int)text_pos & (TEXTHEIGHT - 1);
			text_pos += cube->map->step;
			cube->map->buf[i][cube->map->x] = color_pixel(cube, text_x, text_y);
		}
		else if (i < cube->map->draw_start)
			cube->map->buf[i][cube->map->x] = cube->ceiling->rgb;
		else
			cube->map->buf[i][cube->map->x] = cube->floor->rgb;
		cube->window->data[i * cube->map->width + cube->map->x]
			= cube->map->buf[i][cube->map->x];
	}
}
