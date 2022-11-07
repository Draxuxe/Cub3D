/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:47:37 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/02 10:25:51 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS _H

# define KEY_ESC 53
# define KEY_FRONT 13
# define KEY_BACK 1
# define KEY_RIGHT 2
# define KEY_LEFT 0
# define KEY_LOOK_RIGHT 124
# define KEY_LOOK_LEFT 123
# define KEY_E 14
# define KEY_CLOS
# define TEXTHEIGHT 64
# define TEXTWIDTH 64
# define TEXT_NB 13

// Principal struct
typedef struct s_cubed
{
	struct s_window		*window;
	struct s_sprite		**sprite;
	struct s_calc		*calc;
	struct s_perso		*perso;
	struct s_textures	*textures;
	struct s_colors		*floor;
	struct s_colors		*ceiling;
	struct s_map		*map;
	char				**rawmap;
	long				start;
}			t_cubed;

// Struct for the map
typedef struct s_map
{
	int		width;
	int		height;
	char	**map;

	int		x;
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
	double	move_speed;
	double	rot_speed;
	double	wallx;
	double	step;
	int		**buf;
	int		height_map;
	int		width_map;
	int		door;
	double	*zbuffer;
	int		index_sprite;
	void	*kart;
	int		k_w;
	int		k_h;
	int		k_lright;
	int		k_lleft;
	int		k_rear;
	time_t	time_;
	int		piece;
	long	time_start;
	void	*endwin;
	int		endwin_h;
	int		endwin_w;
	int		sprites;
	int		pieces;
	int		pieces_collected;
	int		end;
	long	tsv;
	long	t;
	long	oldt;
}		t_map;

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

typedef struct s_sprite
{
	double	x;
	double	y;
	double	dist;
	int		position;
	char	c;
}			t_sprite;

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
}		t_perso;

typedef struct s_calc
{
	int		index;
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		v_move_screen;
	int		sprite_height;
	int		sprite_w;
	int		draw_start_x;
	int		draw_end_x;
	int		draw_start_y;
	int		draw_end_y;
	int		stripe;
	int		tex_x;
	int		tex_y;
	int		y;
}			t_calc;

#endif