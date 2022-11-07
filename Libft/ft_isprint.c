/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:44:26 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/02 14:16:30 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	c;

	c = ;
	if (ft_isprint(c) == isprint(c))
	{
		printf("%d  ||  ", isprint(c));
		printf("\033[1;32m%s\n", "TRUE");
	}
	else
		printf("\033[1;31m%s\n", "FALSE");
	return (0);
}
*/