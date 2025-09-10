/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:03:32 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:51:14 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_len(int n, int sign)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len + sign);
}

static char	*ft_trans(char *res, int len, int sign, int n)
{
	res[len] = '\0';
	len--;
	while (len >= 0 + sign)
	{
		res[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	if (sign == 1)
		res[0] = '-';
	return (res);
}

// turns int into str, allocates and returns string
char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*res;

	sign = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		n = -n;
		sign = 1;
	}
	len = ft_len(n, sign);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res = ft_trans(res, len, sign, n);
	return (res);
}
