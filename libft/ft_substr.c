/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:04:45 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:54:51 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static char	*ft_create_substr(char const *s, char *res, unsigned int start,
		size_t len)
{
	size_t	count;
	size_t	rescount;

	count = 0;
	rescount = 0;
	while (count < start)
		count++;
	while (count < (start + len) && s[count] != '\0')
	{
		res[rescount] = s[count];
		rescount++;
		count++;
	}
	res[rescount] = '\0';
	return (res);
}

// returns substr of str starting at start 
//with max size len or NULL if allocation fails
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start || len == 0)
	{
		res = malloc(1);
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (slen - start >= len)
		res = malloc((len + 1) * sizeof(char));
	else
		res = malloc((slen - start + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res = ft_create_substr(s, res, start, len);
	return (res);
}
