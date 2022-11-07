/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:10:38 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/05 17:55:28 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t size)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	ft_memcpy(res, s, size);
	res[size] = 0;
	return (res);
}

static int	split_len(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	tmp;
	char	**split;

	if (!s)
		return (0);
	split = (char **)ft_calloc((split_len(s, c) + 1), sizeof(char *));
	if (!split)
		return (0);
	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		tmp = i;
		while (s[i] && s[i] != c)
			i++;
		if (i != tmp)
			split[j++] = ft_strndup(&s[tmp], i - tmp);
	}
	return (split);
}

/*
int	main(void)
{
	char	**test;
	char	*s;
	char	c;
	size_t	i;

	i = 0;
	s = "           Cec";
	c = ' ';
	test = ft_split(s, c);
	while (test[i])
	{
		printf("%s\n", test[i]);
		free (test[i]);
		i ++;
	}
	free(test);
	return (0);
}
*/