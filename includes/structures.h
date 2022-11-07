/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:47:37 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/02 10:00:52 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define KEY_ESC 53
# define KEY_FRONT 13
# define KEY_BACK 1
# define KEY_RIGHT 2
# define KEY_LEFT 0
# define KEY_E 14
# define KEY_LOOK_RIGHT 124
# define KEY_LOOK_LEFT 123
# define TEXTHEIGHT 64
# define TEXTWIDTH 64

// Principal struct
typedef struct s_cubed
{
	struct s_window		*window;
	struct s_perso		*perso;
	struct s_textures	*textures;
	struct s_colors		*floor;
	struct s_colors		*ceiling;
	struct s_map		*map;
	struct s_data		*data;
	char				**rawmap;
}			t_cubed;

// Struct for the map
typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	int		x;
	double	time;
	double	oldtime;
	int		map_x;
	int		map_y;
	int		hit;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	double	wall_height;
	int		draw_start;
	int		draw_end;
	double	wallx;
	float	step;
	int		**buf;
	int		width_map;
	int		height_map;
}		t_map;

//Struct for player
typedef struct s_perso
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	raydir_x;
	double	raydir_y;
	double	plane_x;
	double	plane_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	camera_x;
	double	perp_wall_dist;
	double	move_speed;
	double	rot_speed;
}		t_perso;

// Struct for textures
typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		**tab;
}		t_textures;

// Struct for colors
typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}		t_colors;

// Struct for the mlx lib
typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		*data;
	char	*addr;
	int		*img_addr;
	int		endian;
	int		bpp;
	int		line_len;
	int		img_width;
	int		img_height;
}			t_window;

#endif