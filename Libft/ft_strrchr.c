/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:40:50 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/04 15:22:42 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		j;
	char	*str;

	i = 0;
	j = -1;
	str = (char *)s;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			j = i;
		i ++;
	}
	if (c == '\0')
		return (&str[i]);
	if (j == -1)
		return (NULL);
	return (&str[j]);
}

/*
int	main(void)
{
	char	*s;
	int		c;

	s = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	c = '\0';
	printf("%s  ||  ", ft_strrchr(s, c));
	printf("%s\n", strrchr(s, c));
	return (0);
}
*/