/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:26:40 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/04 15:27:23 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else if (s1[i] == '\0' || s2[i] == '\0')
			return (0);
		i ++;
	}
	return (0);
}

/*
int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "atoms\0\0\0\0";
	s2 = "atoms\0abc";
	printf("%d  ||  ", ft_strncmp(s1, s2, 8));
	printf("%d\n", strncmp(s1, s2, 8));
	return (0);
}
*/