/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:09:43 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/04 14:51:04 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	c;

	c = ;
	if (ft_isdigit(c) == isdigit(c))
	{
		printf("%d  ||  ", isdigit(c));
		printf("\033[1;32m%s\n", "TRUE");
	else
		printf("\033[1;31m%s\n", "FALSE");
	return (0);
}
*/