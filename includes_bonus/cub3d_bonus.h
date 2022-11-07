/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:15:23 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/07 17:29:16 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <sys/time.h>
# include "../Libft/libft.h"
# include "structures_bonus.h"
# include "../mlx/mlx.h"

//Parsing
	//Map
bool		check_name_map(char *arg);
bool		parse(t_cubed *cubed, char *arg);
void		read_map(t_cubed *cubed, char *arg);
	//Texture
bool		parse_texture(t_cubed **cubed);
	//Colors
bool		parse_colors(t_cubed **cubed);
	//Map
bool		parse_map(t_cubed **cubed);
bool		ft_isspawn(char c);
	//Check
bool		check_params(t_cubed **cubed);
int			check_line(char *s, int j, t_map *map, int *spawn);
bool		check_unclosedwall(t_map *map, int j, char *s);
bool		check_walls(t_map *map, char *s, int j);

//Init
	//Spawn
void		init_map(t_map *map, int i, int j);
void		ft_init_cube(t_cubed *cube);

	//Window
void		ft_init_window(t_cubed *cubed);

//Utils
	//Find
int			findline(char **map, char *way, int length);
bool		findthisline(char *str, char *way, int length);
int			findstart(char **map);
int			findx(t_map *map);
bool		find_double(char **map);
	//Array
size_t		size_array(char **s);
	//Free
void		free_array(char **split);
void		free_cubed(t_cubed *cubed);

//Get_Next_Line
char		*get_next_line(int fd);

// MInimap
void		ft_minimap(t_cubed *cube);

//	Predraw
void		ft_predraw(t_cubed *cube);

//raycasting
void		ft_calc(t_cubed *cube);
void		ft_get_step(t_cubed *cube);
void		ft_colision(t_cubed *cube);
void		ft_draw_start_end(t_cubed *cube);
void		ft_draw(t_cubed *cube);
void		ft_sprite(t_cubed *cube);
void		calc_fps(t_cubed *cube);

//Move
int			ft_key_press(int key_code, t_cubed *cube);

//Window
void		ft_open_window( t_cubed *cube );
int			ft_exit(t_cubed *cube);

//key press
int			ft_key_press(int key_code, t_cubed *cube);
double		get_move_y(t_cubed *cube);
double		get_move_x(t_cubed *cube);

//key push
void		move_front(t_cubed *cube);
void		move_down(t_cubed *cube);
void		ft_key_e(t_cubed *cube);

//mouse
void		look_left(t_cubed *cube);
int			mouse_move_hook(int x, int y, t_cubed *cube);
void		look_right(t_cubed *cube);

//sprite
void		ft_sprite_order(t_cubed *cube);

//init_struct
int			**ft_lock_tab(t_cubed *cube);
void		ft_load(t_cubed *cube, int *link, char *path, t_window *img);
void		ft_preload(t_cubed *cube);
int			**ft_lock_texture( void );
t_sprite	**ft_lock_sprite(t_cubed *cube);

//kart
void		ft_print_kart(t_cubed *cube);
void		ft_kart(t_cubed *cube);

//piece
void		ft_piece(t_cubed *cube);
void		ft_count_sprites(t_cubed *cube);
bool		ft_objs(char c);

//calc sprite
void		ft_calc_sprite(t_cubed *cube);

#endif