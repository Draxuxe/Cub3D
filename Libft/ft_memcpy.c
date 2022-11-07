/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:56:36 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/05 14:21:32 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	i = 0;
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	while (i < n)
	{
		dest[i] = source[i];
		i ++;
	}
	return (dst);
}

/*
int	main(void)
{
	printf("%s  ||  ", memcpy(((void *)0), ((void *)0), 3));
	printf("%s\n", memcpy(((void *)0), ((void *)0), 3));
	return (0);
}
*/