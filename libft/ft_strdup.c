/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:07:54 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:53:00 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//copies src string to allocated string 
char	*ft_strdup(const char *src)
{
	int		strl;
	char	*res;
	int		count;

	strl = ft_strlen(src);
	res = malloc((strl + 1) * sizeof(char));
	count = 0;
	if (res == NULL)
		return (NULL);
	while (src[count] != '\0')
	{
		res[count] = src[count];
		count++;
	}
	res[count] = '\0';
	return (res);
}
