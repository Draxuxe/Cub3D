/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:42:50 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/03 11:17:47 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)b;
	while (i < len)
	{
		s[i] = (unsigned char)c;
		i ++;
	}
	return (s);
}

/*
int	main(void)
{
	int		c;
	size_t	len;
	char	*b;

	c = 'a';
	len = 10;
	b = malloc(sizeof(char) * len + 1);
	printf("%s  ||  ", ft_memset(b, c, len));
	printf("%s\n", memset(b, c, len));
	free (b);
	return (0);
}
*/