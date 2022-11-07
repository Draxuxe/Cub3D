/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:22:24 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/04 14:51:24 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
int	main(void)
{
	int	c;

	c = 70;
	printf("%d  ||  ", c);
	printf("%c\n", (unsigned char)c);
	if (tolower(c) == ft_tolower(c))
	{
		printf("%d  ||  ", tolower(c));
		printf("%c  ||  ", (unsigned char)tolower(c));
		printf("\033[1;32m%s\n", "TRUE");
	}
	else
		printf("\033[1;31m%s\n", "FALSE");
	return (0);
}
*/