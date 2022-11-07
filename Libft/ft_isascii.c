/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:36:11 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/02 14:17:18 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	c;

	c = ;
	if (ft_isascii(c) == isascii(c))
	{
		printf("%d  ||  ", isascii(c));
		printf("\033[1;32m%s\n", "TRUE");
	}
	else
		printf("\033[1;31m%s\n", "FALSE");
	return (0);
}
*/