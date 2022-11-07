/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:23:25 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/02 10:34:27 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	**ft_lock_tab(t_cubed *cube)
{
	int	i;
	int	j;
	int	**tab;

	tab = malloc(sizeof(int *) * cube->map->height);
	if (!tab)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < cube->map->height)
	{
		tab[i] = malloc(sizeof(int) * cube->map->width);
		if (!tab[i])
			exit (EXIT_FAILURE);
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

void	ft_load(t_cubed *cube, int *link, char *path, t_window *img)
{
	int	i;
	int	j;

	img->img = mlx_xpm_file_to_image(cube->window->mlx, path,
			&img->img_width, &img->img_height);
	if (!img->img)
	{
		ft_putstr_fd("Error\nA Texture is empty.\n", 2);
		exit(EXIT_FAILURE);
	}
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
}

void	ft_preload(t_cubed *cube)
{
	t_window	img;

	ft_load(cube, cube->textures->tab[0], cube->textures->north, &img);
	ft_load(cube, cube->textures->tab[1], cube->textures->south, &img);
	ft_load(cube, cube->textures->tab[2], cube->textures->east, &img);
	ft_load(cube, cube->textures->tab[3], cube->textures->west, &img);
	ft_load(cube, cube->textures->tab[4], "./textures/bar_close.xpm", &img);
	ft_load(cube, cube->textures->tab[5], "./textures/bar_open.xpm", &img);
	ft_load(cube, cube->textures->tab[6], "./textures/finish.xpm", &img);
	ft_load(cube, cube->textures->tab[7], "./textures/1.xpm", &img);
	ft_load(cube, cube->textures->tab[8], "./textures/2.xpm", &img);
	ft_load(cube, cube->textures->tab[9], "./textures/3.xpm", &img);
	ft_load(cube, cube->textures->tab[10], "./textures/4.xpm", &img);
	ft_load(cube, cube->textures->tab[11], "./textures/5.xpm", &img);
	ft_load(cube, cube->textures->tab[12], "./textures/6.xpm", &img);
}

int	**ft_lock_texture( void )
{
	int			i;
	int			**tab;

	tab = malloc(sizeof(int *) * TEXT_NB);
	if (!tab)
		exit(1);
	i = 0;
	while (i < TEXT_NB)
	{
		tab[i] = malloc(sizeof(int) * (TEXTHEIGHT * TEXTWIDTH));
		if (!tab[i])
			exit(EXIT_FAILURE);
		i++;
	}
	return (tab);
}

t_sprite	**ft_lock_sprite(t_cubed *cube)
{
	int			i;
	t_sprite	**sprite;

	i = -1;
	if (cube->sprite)
	{
		while (cube->sprite[++i])
			free(cube->sprite[i]);
		free(cube->sprite);
	}
	sprite = malloc(sizeof(t_sprite *) * (cube->map->sprites + 1));
	if (!sprite)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < cube->map->sprites)
	{
		sprite[i] = malloc(sizeof(t_sprite));
		if (!sprite[i])
			exit(EXIT_FAILURE);
	}
	sprite[cube->map->sprites] = NULL;
	return (sprite);
}
