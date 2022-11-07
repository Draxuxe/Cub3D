/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:35:45 by lfilloux          #+#    #+#             */
/*   Updated: 2021/11/04 18:17:26 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(long long result, short minus)
{
	if (result > 2147483648 || result < -2147483649)
	{
		if (minus == 1)
			return (-1);
		return (0);
	}
	return ((int)result * minus);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	short			minus;
	long long		result;

	i = 0;
	minus = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i ++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i ++;
	}
	return (ft_check(result, minus));
}

/*
int	main(void)
{
	char	n[40] = "99999999999999999999999999";

	printf("%d  ||  ", ft_atoi(n));
	printf("%d\n", atoi(n));
	return (0);
}
*/