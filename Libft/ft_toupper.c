/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:14:21 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/04 14:51:15 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*
int	main(void)
{
	int	c;

	c = 97;
	printf("%d  ||  ", c);
	printf("%c\n", (unsigned char)c);
	if (toupper(c) == ft_toupper(c))
	{
		printf("%d  ||  ", toupper(c));
		printf("%c  ||  ", (unsigned char)toupper(c));
		printf("\033[1;32m%s\n", "TRUE");
	}
	else
		printf("\033[1;31m%s\n", "FALSE");
	return (0);
}
*/