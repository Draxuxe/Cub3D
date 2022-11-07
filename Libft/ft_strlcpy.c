/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:29:53 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/03 10:03:05 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i ++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
int	main(void)
{
	char	*dest;
	char	*dst;
	char	*test;

	dest = malloc(sizeof(char) * 15);
	dst = malloc(sizeof(char) * 15);
	test = "Salut tout ce beau monde";
	printf("%zu  ||  ", ft_strlcpy(dst, test, 23));
	printf("%zu\n", strlcpy(dest, test, 23));
	free (dst);
	free (dest);
	return (0);
}
*/