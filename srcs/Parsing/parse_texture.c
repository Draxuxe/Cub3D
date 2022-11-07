/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:20:24 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/02 14:34:08 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	find_path(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '.')
		i ++;
	if (!s[i])
		return (0);
	return (i);
}

static bool	findtexture(char **map)
{
	int			n;
	int			e;
	int			s;
	int			w;

	n = findline(map, "NO ", 3);
	s = findline(map, "SO ", 3);
	w = findline(map, "WE ", 3);
	e = findline(map, "EA ", 3);
	if (n < 0 || s < 0 || w < 0 || e < 0)
	{
		ft_putstr_fd("Error\nThey seem to be a problem with the textures.\n", 2);
		return (false);
	}
	return (true);
}

static t_textures	*gettexture(t_cubed *cubed, char **map)
{
	int			n;
	int			e;
	int			s;
	int			w;
	t_textures	*textures;

	textures = malloc(sizeof(t_textures));
	if (!textures)
		return (NULL);
	n = findline(cubed->rawmap, "NO ", 3);
	e = findline(cubed->rawmap, "EA ", 3);
	s = findline(cubed->rawmap, "SO ", 3);
	w = findline(cubed->rawmap, "WE ", 3);
	textures->north = ft_strtrim(&map[n][find_path(map[n])], "\n");
	textures->east = ft_strtrim(&map[e][find_path(map[e])], "\n");
	textures->south = ft_strtrim(&map[s][find_path(map[s])], "\n");
	textures->west = ft_strtrim(&map[w][find_path(map[w])], "\n");
	return (textures);
}

static bool	texture_valid(char *path)
{
	int	fd;
	int	end;

	end = ft_strlen(path);
	if (end == 0 || (path[end - 1] != 'm' || path[end - 2] != 'p'
			|| path[end - 3] != 'x' || path[end - 4] != '.'))
		return (false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close (fd);
		return (false);
	}
	close (fd);
	return (true);
}

bool	parse_texture(t_cubed **cubed)
{
	if (findtexture((*cubed)->rawmap) == false)
		return (false);
	(*cubed)->textures = gettexture((*cubed), (*cubed)->rawmap);
	if (find_double((*cubed)->rawmap))
	{
		ft_putstr_fd("Error\nThere is a param in double.\n", 2);
		return (false);
	}
	if (!texture_valid((*cubed)->textures->north)
		|| !texture_valid((*cubed)->textures->south)
		|| !texture_valid((*cubed)->textures->east)
		|| !texture_valid((*cubed)->textures->west))
	{
		ft_putstr_fd("Error\nA Texture is invalid.\n", 2);
		return (false);
	}
	return (true);
}
