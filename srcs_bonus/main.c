/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:00:42 by aleferra          #+#    #+#             */
/*   Updated: 2022/11/02 14:38:21 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

int	main(int ac, char **av)
{
	t_cubed	cubed;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nOnly one argument needed(The map). Try again!\n", 2);
		return (1);
	}
	if (!check_name_map(av[1]))
		return (1);
	if (!parse(&cubed, av[1]))
		exit(EXIT_FAILURE);
	ft_open_window(&cubed);
	return (0);
}
