/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:43:14 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/02 15:02:17 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *)s;
	while (i < n)
	{
		dest[i] = '\0';
		i ++;
	}
}

/*
int	main(void)
{
	char	*s;
	char	*test;
	size_t	len;

	len = 10;
	s = malloc(sizeof(char) * len + 1);
	test = malloc(sizeof(char) * len + 1);
	ft_bzero(s, len);
	bzero(test, len);
	printf ("%s  ||  %s\n", s, test);
	free (s);
	free (test);
	return (0);
}
*/