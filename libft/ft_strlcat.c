/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:32:04 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:53:47 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// appends src to dest with dest maximum size of nbytes.
// Returns length of intended string(dest und src)nullterminates dest
size_t	ft_strlcat(char *dest, const char *src, size_t nbytes)
{
	size_t	destcount;
	size_t	destcres;
	size_t	count;

	destcount = 0;
	count = 0;
	while (dest[destcount] != '\0' && destcount < nbytes)
		destcount++;
	destcres = destcount;
	if (nbytes <= destcount)
		return (destcount + ft_strlen(src));
	while (destcount + 1 < nbytes && src[count] != '\0')
	{
		dest[destcount] = src[count];
		destcount++;
		count++;
	}
	dest[destcount] = '\0';
	return (destcres + (ft_strlen(src)));
}

/* size_t	ft_strlcat(char *restrict dst, 
const char *restrict src, size_t dstsize)
{
	size_t	dstcount;
	size_t	srccount;

	dstcount = 0;
	srccount = 0;
	while (src[srccount] != '\0')
		srccount++;
	if (dstsize == 0)
		return (srccount);
	while (dst[dstcount] != '\0')
		dstcount++;
	if (dstcount > dstsize)
		return (srccount + dstsize);
	srccount = 0;
	while (dstcount + 1 < dstsize && src[srccount] != '\0')
	{
		dst[dstcount] = src[srccount];
		dstcount++;
		srccount++;
	}
	dst[dstcount] = '\0';
	return (dstsize + srccount);
} */
