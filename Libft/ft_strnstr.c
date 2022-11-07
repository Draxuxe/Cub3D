/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:09:27 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/03 15:34:38 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (i + j < len && haystack[i + j] == needle[j])
		{
			j ++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i ++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	*source;
	char	*find;

	source = "Bonjour tout le monde";
	find = "tout";
	printf("%s  ||  ", ft_strnstr(source, find, 20));
	printf("%s\n", strnstr(source, find, 20));
	return (0);
}
*/