/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:38:01 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/05 14:25:08 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i ++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	*s;
	int		c;

	s = "123456789123456789";
	c = '3';
	printf("%s  ||  ", ft_memchr(s, c, 1));
	printf("%s", memchr(s, c, 1));
	return (0);
}
*/