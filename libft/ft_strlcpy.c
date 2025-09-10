/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:15:49 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:53:53 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// copies size_t bytes from src to dest
// returns len of intended str

size_t	ft_strlcpy(char *dest, const char *src, size_t nbytes)
{
	size_t	count;
	size_t	srccount;

	srccount = 0;
	count = 0;
	while (src[srccount] != '\0')
		srccount++;
	if (nbytes == 0 || dest == 0)
		return (srccount);
	else
	{
		while (count < nbytes - 1 && src[count] != '\0')
		{
			dest[count] = src[count];
			count++;
		}
	}
	dest[count] = '\0';
	return (srccount);
}

/* size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
		size_t	count;
	size_t	srccount;
	
	count = 0;
	srccount = 0;
	while (src[srccount] != '\0')
		srccount++;
	if (dstsize == 0 || dst == NULL)
		return (srccount);
	while (count < dstsize - 1 && src[count] != '\0')
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (srccount);
} */
