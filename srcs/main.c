/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:00:42 by aleferra          #+#    #+#             */
/*   Updated: 2022/10/27 16:32:25 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_open_window(t_cubed *cube)
{
	t_window	*wind;

	wind = malloc(sizeof(t_window));
	if (!wind)
		return ;
	cube->window = wind;
	cube->map->width = 1920;
	cube->map->height = 1080;
	cube->window->mlx = mlx_init();
	cube->map->buf = ft_lock_tab(cube);
	cube->textures->tab = ft_lock_texture();
	if (!ft_preload(cube))
		exit(EXIT_FAILURE);
	cube->window->mlx_win = mlx_new_window(cube->window->mlx, cube->map->width,
			cube->map->height, "cub3d");
	cube->window->img = mlx_new_image(cube->window->mlx,
			cube->map->width, cube->map->height);
	cube->window->data = (int *)mlx_get_data_addr(cube->window->img,
			&cube->window->bpp, &cube->window->line_len, &cube->window->endian);
	mlx_loop_hook(cube->window->mlx, ft_raycast, cube);
	mlx_hook(cube->window->mlx_win, 17, 0, ft_exit, cube);
	mlx_hook(cube->window->mlx_win, 2, 0, ft_key_press, cube);
	mlx_loop(cube->window->mlx);
}

int	main(int ac, char **av)
{
	t_cubed	cubed;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nOne argument needed(The map). Try again!\n", 2);
		return (1);
	}
	if (!check_name_map(av[1]))
		return (1);
	if (!parse(&cubed, av[1]))
		ft_exit(&cubed);
	ft_open_window(&cubed);
	return (0);
}
