/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:29:27 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/05 17:43:11 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count ++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		count ++;
		nb = nb / 10;
	}
	return (count);
}

static void	ft_decrementation(char *dest, int len, long nb)
{
	char	*base;

	base = "0123456789";
	if (nb >= 10)
		ft_decrementation(dest, len - 1, nb / 10);
	dest[len] = base[nb % 10];
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*dest;

	nb = (long)n;
	len = ft_len(nb);
	dest = (char *)malloc(sizeof(char) * (len + 2));
	if (!dest)
		return (NULL);
	if (nb < 0)
	{
		dest[0] = '-';
		nb = -nb;
	}
	ft_decrementation(dest, len, nb);
	dest[len + 1] = '\0';
	return (dest);
}

/*
int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}
*/