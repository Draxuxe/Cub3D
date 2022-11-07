/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:56:47 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/04 16:49:24 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i])
		i ++;
	if (i < dstsize)
	{
		while (src[j] && i < dstsize - 1)
		{	
			dst[i] = src[j];
			i ++;
			j ++;
		}
		dst[i] = '\0';
	}
	while (src[j])
	{
		i ++;
		j ++;
	}
	return (i);
}

/*
int	main(void)
{
	char	*dst;
	char	*dest;
	char	*source;

	dst = "Bonjour, ";
	dest = "Bonjour, ";
	source = "tout le monde.";
	printf("%zu  ||  ", ft_strlcat(dst, source, 10));
	printf("%zu\n", strlcat(dest, source, 10));
	return (0);
}
*/