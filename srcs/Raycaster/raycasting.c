/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:45:54 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/02 10:41:56 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_raycast(t_cubed *cube)
{
	cube->map->x = 0;
	while (cube->map->x < cube->map->width)
	{
		ft_calc(cube);
		ft_get_step(cube);
		ft_collision(cube);
		ft_draw_start_end(cube);
		ft_predraw(cube);
		cube->map->x++;
	}
	mlx_clear_window(cube->window->mlx, cube->window->mlx_win);
	mlx_put_image_to_window(cube->window->mlx,
		cube->window->mlx_win, cube->window->img, 0, 0);
	return (1);
}

int	**ft_lock_tab(t_cubed *cube)
{
	int	i;
	int	j;
	int	**tab;

	tab = malloc(sizeof(int *) * cube->map->height);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < cube->map->height)
	{
		tab[i] = malloc(sizeof(int) * cube->map->width);
		if (!tab[i])
			return (NULL);
		i++;
	}
	i = -1;
	while (++i < cube->map->height)
	{
		j = -1;
		while (++j < cube->map->width)
			tab[i][j] = 0;
	}
	return (tab);
}

static bool	ft_load(t_cubed *cube, int *link, char *path, t_window *img)
{
	int	i;
	int	j;

	img->img = mlx_xpm_file_to_image(cube->window->mlx, path,
			&img->img_width, &img->img_height);
	if (!img->img)
		return (false);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	i = 0;
	while (i < img->img_height)
	{
		j = 0;
		while (j < img->img_width)
		{
			link[img->img_width * i + j] = img->data[img->img_width * i + j];
			j++;
		}
		i++;
	}
	mlx_destroy_image(cube->window->mlx, img->img);
	return (true);
}

bool	ft_preload(t_cubed *cube)
{
	t_window	img;
	int			i;

	i = 0;
	i += ft_load(cube, cube->textures->tab[0], cube->textures->north, &img);
	i += ft_load(cube, cube->textures->tab[1], cube->textures->south, &img);
	i += ft_load(cube, cube->textures->tab[2], cube->textures->east, &img);
	i += ft_load(cube, cube->textures->tab[3], cube->textures->west, &img);
	if (i != 4)
	{
		ft_putstr_fd("Error\nA Texture is empty\n", 2);
		return (false);
	}
	return (true);
}
