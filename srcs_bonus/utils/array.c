/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:39:02 by lfilloux          #+#    #+#             */
/*   Updated: 2022/11/02 15:01:13 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	free_array(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free (split[i]);
		i ++;
	}
	free (split);
}

size_t	size_array(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i ++;
	return (i);
}

bool	find_double(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (map[++j])
	{
		if (!ft_strncmp(map[j], "NO ", 3) || !ft_strncmp(map[j], "EA ", 3)
			|| !ft_strncmp(map[j], "WE ", 3) || !ft_strncmp(map[j], "SO ", 3)
			|| !ft_strncmp(map[j], "F ", 2) || !ft_strncmp(map[j], "C ", 2))
			i ++;
	}
	if (i > 6)
		return (true);
	return (false);
}
