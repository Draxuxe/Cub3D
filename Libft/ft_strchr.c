/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:28:47 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/04 15:01:43 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i ++;
	}
	if (c == '\0')
		return (&str[i]);
	return (NULL);
}

/*
int	main(void)
{
	char	*s;
	int		c;

	s = "Salut!";
	c = 'l';
	printf("%s  ||  ", ft_strchr(s, c));
	printf("%s\n", strchr(s, c));
	return (0);
}
*/