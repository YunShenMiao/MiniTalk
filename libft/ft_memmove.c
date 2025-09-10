/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:11:01 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:52:04 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//copies memory from source to dest up until nbytes
//prevents overflow
void	*ft_memmove(void *dest, const void *source, size_t nbytes)
{
	unsigned int	count;
	char			*dtemp;
	const char		*stemp;

	count = 0;
	dtemp = dest;
	stemp = source;
	if (nbytes == 0 || (dest == NULL && source == NULL))
		return (dest);
	else if (dest < source || dest >= source + nbytes)
	{
		while (nbytes--)
			*dtemp++ = *stemp++;
	}
	else
	{
		count = nbytes;
		while (count > 0)
		{
			dtemp[count - 1] = stemp[count - 1];
			count--;
		}
	}
	return (dest);
}
