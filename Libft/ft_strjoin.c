/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:21:31 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/05 17:45:33 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (dest)
	{
		while (s1[i])
			dest[j++] = s1[i++];
		i = 0;
		while (s2[i])
			dest[j++] = s2[i++];
		dest[j] = '\0';
		return (dest);
	}
	return (NULL);
}

/*
int	main(int ac, char **av)
{
	char	*dest;

	if (ac != 3)
		return (0);
	dest = ft_strjoin(av[1], av[2]);
	printf("%s\n", dest);
	free (dest);
	return (0);
}
*/