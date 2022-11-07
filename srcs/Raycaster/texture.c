/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:07:01 by lfilloux          #+#    #+#             */
/*   Updated: 2022/10/24 15:12:07 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_text(t_cubed *cube, int text_y, int text_x)
{
	int	color;

	color = 0xb640ff;
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

int	get_text_x(t_cubed *cube)
{
	int	text_x;

	text_x = (int)(cube->map->wallx * (double)TEXTWIDTH);
	if (cube->map->side == 0 && cube->perso->raydir_x > 0)
		text_x = TEXTWIDTH - text_x - 1;
	else if (cube->map->side == 1 && cube->perso->raydir_y < 0)
		text_x = TEXTWIDTH - text_x - 1;
	return (text_x);
}

int	**ft_lock_texture(void)
{
	int			i;
	int			**tab;

	tab = malloc(sizeof(int *) * 4);
	if (!tab)
		exit(1);
	i = 0;
	while (i < 4)
	{
		tab[i] = malloc(sizeof(int) * (TEXTHEIGHT * TEXTWIDTH));
		if (!tab[i])
			exit(1);
		i++;
	}
	return (tab);
}
