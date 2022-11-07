/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:45:54 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/07 14:52:39 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	ft_display_map(t_cubed *cube)
{
	mlx_clear_window(cube->window->mlx, cube->window->mlx_win);
	mlx_put_image_to_window(cube->window->mlx, cube->window->mlx_win,
		cube->window->img, 0, 0);
	ft_kart(cube);
}

static void	ft_display_end(t_cubed *cube)
{
	long				end;
	struct timeval		time;

	gettimeofday(&time, NULL);
	end = time.tv_sec * 1000 + time.tv_usec / 1000;
	end -= cube->start;
	if (end >= 300)
		cube->start = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (end < 150)
		cube->map->endwin = mlx_xpm_file_to_image(cube->window->mlx,
				"./textures/end.xpm",
				&cube->map->endwin_w, &cube->map->endwin_h);
	else
		cube->map->endwin = mlx_xpm_file_to_image(cube->window->mlx,
				"./textures/end1.xpm",
				&cube->map->endwin_w, &cube->map->endwin_h);
	mlx_clear_window(cube->window->mlx, cube->window->mlx_win);
	mlx_put_image_to_window(cube->window->mlx, cube->window->mlx_win,
		cube->map->endwin, 0, 0);
}

void	ft_display(t_cubed *cube)
{
	if (cube->map->end == 1)
		ft_display_end(cube);
	else
		ft_display_map(cube);
}

int	ft_raycast(t_cubed *cube)
{
	calc_fps(cube);
	mlx_mouse_hide();
	ft_count_sprites(cube);
	cube->sprite = ft_lock_sprite(cube);
	ft_piece(cube);
	cube->map->x = 0;
	while (cube->map->x < cube->map->width)
	{
		ft_calc(cube);
		ft_get_step(cube);
		ft_colision(cube);
		ft_draw_start_end(cube);
		ft_predraw(cube);
		cube->map->zbuffer[cube->map->x] = cube->map->perp_wall_dist;
		cube->map->x++;
	}
	ft_sprite_order(cube);
	ft_calc_sprite(cube);
	cube->map->x = -1;
	while (++cube->map->x < cube->map->width)
		ft_minimap(cube);
	ft_display(cube);
	return (1);
}

void	ft_open_window( t_cubed *cube )
{
	ft_init_cube(cube);
	ft_preload(cube);
	cube->window->mlx_win = mlx_new_window(cube->window->mlx, cube->map->width,
			cube->map->height, "cub3d");
	cube->window->img = mlx_new_image(cube->window->mlx, cube->map->width,
			cube->map->height);
	cube->window->data = (int *)mlx_get_data_addr(cube->window->img,
			&cube->window->bpp, &cube->window->line_len, &cube->window->endian);
	mlx_loop_hook(cube->window->mlx, ft_raycast, cube);
	mlx_hook(cube->window->mlx_win, 17, 0, ft_exit, cube);
	mlx_hook(cube->window->mlx_win, 2, 0, ft_key_press, cube);
	mlx_hook(cube->window->mlx_win, 6, 1L << 6, &mouse_move_hook, cube);
	mlx_loop(cube->window->mlx);
}
