/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:24:23 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:54:11 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//allocates mem for new string in which stores
// old str after function f
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*res;

	count = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s[count] != '\0')
	{
		res[count] = f(count, s[count]);
		count++;
	}
	res[count] = '\0';
	return (res);
}
/*
char	ft_t(unsigned int x, char c)
{
	if (x % 2 == 0 && c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
char	ft_add_char(unsigned int x, char c)
{
	return (c + (x % 2));
}*/