/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:12:31 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/02 14:17:50 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	c;

	c = ;
	if (ft_isalnum(c) == isalnum(c))
	{
		printf("%d  ||  ", isalnum(c));
		printf("\033[1;32m%s\n", "TRUE");
	}
	else
		printf("\033[1;31m%s\n", "FALSE");
	return (0);
}
*/