/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:57:58 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/07 17:29:32 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

bool	check_walls(t_map *map, char *s, int j)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ' && s[i] == '1')
		i ++;
	while (s[i])
	{
		if ((s[i] == '0' && s[i + 1] && s[i + 1] == ' ')
			|| (s[i] == '0' && s[i - 1] && s[i - 1] == ' '))
			return (false);
		if ((i >= (int)ft_strlen(map->map[j + 1]) && s[i] == '0')
			|| (i >= (int)ft_strlen(map->map[j - 1]) && s[i] == '0'))
			return (false);
		i ++;
	}
	return (true);
}

bool	parse(t_cubed *cubed, char *arg)
{
	read_map(cubed, arg);
	if (!parse_texture(&cubed) || !parse_colors(&cubed) || !parse_map(&cubed))
		return (false);
	if (!check_params(&cubed))
		return (false);
	return (true);
}
