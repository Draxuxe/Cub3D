/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:41:03 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/05 17:45:48 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (!s)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
char	add(unsigned int i, char c)
{
	c = c + (unsigned char)i;
	return (c);
}

int	main(void)
{
	char	*s;

	s = ft_strmapi("JSP", &add);
	printf("%s\n", s);
	free (s);
	return (0);
}
*/