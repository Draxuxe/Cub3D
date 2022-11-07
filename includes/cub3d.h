/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:15:23 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/07 17:29:04 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include "../Libft/libft.h"
# include "structures.h"
# include "../mlx/mlx.h"

//Parsing
	//Map
bool	check_name_map(char *arg);
bool	parse(t_cubed *cubed, char *arg);
void	read_map(t_cubed *cubed, char *arg);
	//Texture
bool	parse_texture(t_cubed **cubed);
	//Colors
bool	parse_colors(t_cubed **cubed);
	//Map
bool	parse_map(t_cubed **cubed);
bool	ft_isspawn(char c);
	//Check
bool	check_params(t_cubed **cubed);
int		check_line(char *s, int j, t_cubed *cube, int *spawn);
bool	check_unclosedwall(t_map *map, int j, char *s);
bool	check_walls(t_map *map, char *s, int j);

//Init
	//Spawn
void	init_map(t_map *map);
	//Player
t_perso	*init_perso(t_cubed *cube, int i, int j);

//Utils
	//Find
int		findline(char **map, char *way, int length);
bool	findthisline(char *str, char *way, int length);
int		findstart(char **map);
int		findx(t_map *map);
bool	find_double(char **map);
	//Array
size_t	size_array(char **s);
	//Free
void	free_array(char **split);
	//Exit
int		ft_exit(t_cubed *cube);
	//Get_Next_Line
char	*get_next_line(int fd);

//Raycaster
	//Engine
void	ft_calc(t_cubed *cube);
void	ft_get_step(t_cubed *cube);
void	ft_collision(t_cubed *cube);
int		ft_raycast(t_cubed *cube);
bool	ft_preload(t_cubed *cube);
	//Drawing
void	ft_predraw(t_cubed *cube);
void	ft_draw(t_cubed *cube);
void	ft_draw_start_end(t_cubed *cube);
	//Textures
int		**ft_lock_texture(void);
int		**ft_lock_tab(t_cubed *cube);
int		get_text_x(t_cubed *cube);
int		get_text(t_cubed *cube, int text_y, int text_x);
	//Movements
int		ft_key_press(int key_code, t_cubed *cube);
double	get_move_y(t_cubed *cube);
double	get_move_x(t_cubed *cube);
void	move_front(t_cubed *cube);
void	move_down(t_cubed *cube);
void	move_left(t_cubed *cube);
void	move_right(t_cubed *cube);

#endif