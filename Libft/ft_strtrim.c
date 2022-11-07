/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:39:26 by lfilloux          #+#    #+#             */
/*   Updated: 2022/10/24 12:31:31 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	diff(char c, const char *no)
{
	size_t	i;

	i = 0;
	while (no[i])
	{
		if (c == no[i])
			return (1);
		i ++;
	}
	return (0);
}

static size_t	get_end(char const *s, char const *no)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	while (i > 0 && (diff(s[i], no)))
		i --;
	return (i + 1);
}

static size_t	get_start(char const *s, char const *no)
{
	size_t	i;

	i = 0;
	while (s[i] && (diff(s[i], no)))
		i ++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	len;
	char	*dest;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	len = (end - start);
	if (start == ft_strlen(s1))
		len = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest)
	{
		while (start < end)
			dest[i++] = s1[start++];
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}

/*
int	main(void)
{
	char	*dest;
	char	*s1 = "\t   \n\n\n  \n\n\t ";
	char	*s2 = "";

	dest = ft_strtrim(s1, " \n\t");
	printf("%s\n", dest);
	free (dest);
	return (0);
}
*/