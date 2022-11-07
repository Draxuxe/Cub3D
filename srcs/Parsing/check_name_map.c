/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:20:19 by lfilloux          #+#    #+#             */
/*   Updated: 2022/10/20 11:42:01 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	check_name_map(char *arg)
{
	int	end;

	end = ft_strlen(arg);
	if (end == 0 || (arg[end - 1] != 'b' || arg[end - 2] != 'u'
			|| arg[end - 3] != 'c' || arg[end - 4] != '.'))
	{
		if (end == 0)
			ft_putstr_fd("Error\nArgument is empty.\n", 2);
		else if (arg[end] != 'b' || arg[end - 1] != 'u' || arg[end - 2] != 'c'
			|| arg[end - 3] != '.')
			ft_putstr_fd("Error\nWrong file extension. Needs to be '.cub'.\n", 2);
		return (false);
	}
	return (true);
}
