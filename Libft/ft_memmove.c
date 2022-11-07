/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:09:08 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/05 14:23:22 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*dest;

	i = -1;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dest > source)
		while (len--)
			dest[len] = source[len];
	else
	{
		while (++i, len--)
			dest[i] = source[i];
	}
	return (dest);
}

/*
int	main(void)
{
	printf("%s  ||  ", memmove(((void *)0), ((void *)0), 5));
	printf("%s\n", memmove(((void *)0), ((void *)0), 5));
	return (0);
}
*/