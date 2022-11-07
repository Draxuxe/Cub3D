/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:20:29 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/02 14:57:37 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

bool	wrongcode(char **colors)
{
	int	i;

	i = 0;
	if (!colors)
		return (false);
	while (colors[i])
	{
		if (ft_strlen(colors[i]) > 3)
			return (false);
		i ++;
	}
	if (i != 3)
		return (false);
	return (true);
}

static t_colors	*getcolor(char *c)
{
	t_colors	*color;
	char		**colors;

	color = malloc(sizeof(t_colors));
	if (!color)
		return (NULL);
	colors = ft_split(c, ',');
	free(c);
	if (!wrongcode(colors))
	{
		ft_putstr_fd("Error\nThe RGB code is invalid.\n", 2);
		free_array(colors);
		return (NULL);
	}
	color->r = ft_atoi(colors[0]);
	color->g = ft_atoi(colors[1]);
	color->b = ft_atoi(colors[2]);
	color->rgb = (0 << 24 | color->r << 16 | color->g << 8 | color->b);
	free_array(colors);
	return (color);
}

static bool	getcolorline(char **map)
{
	int	f;
	int	c;

	f = findline(map, "F ", 2);
	c = findline(map, "C ", 2);
	if (f < 0 || c == false)
	{
		ft_putstr_fd("Error\nSeem to be a problem with a color.\n", 2);
		return (false);
	}
	return (true);
}

static bool	checkrgb(t_cubed *cubed, int f, int c)
{
	char	*floor;
	char	*ceil;

	floor = ft_strtrim(cubed->rawmap[f], "F \n");
	ceil = ft_strtrim(cubed->rawmap[c], "C \n");
	if (!floor || !floor[0] || !ceil || !ceil[0])
	{
		if (floor)
			free(floor);
		if (ceil)
			free(ceil);
		ft_putstr_fd("Error\nThere is no RGB code.\n", 2);
		return (false);
	}
	free(floor);
	free(ceil);
	return (true);
}

bool	parse_colors(t_cubed **cubed)
{
	int			c;
	int			f;

	if (!getcolorline((*cubed)->rawmap))
		return (false);
	f = findline((*cubed)->rawmap, "F ", 2);
	c = findline((*cubed)->rawmap, "C ", 2);
	if (!checkrgb(*cubed, f, c))
		return (false);
	(*cubed)->floor = getcolor(ft_strtrim((*cubed)->rawmap[f], "F \n"));
	(*cubed)->ceiling = getcolor(ft_strtrim((*cubed)->rawmap[c], "C \n"));
	if (!(*cubed)->floor || !(*cubed)->ceiling)
		return (false);
	return (true);
}
