/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:50:16 by lfilloux          #+#    #+#             */
/*   Updated: 2022/10/06 16:57:45 by lfilloux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i ++;
	return (i);
}

/*
int	main(int argc, char **argv)
{
	int	x;

	x = 1;
	if (argc < 2)
		return (0);
	while (x < argc)
	{
		printf("%zu ||  ", ft_strlen(argv[x]));
		printf("%zu\n", strlen(argv[x]));
		x ++;
	}
	return (0);
}
*/
