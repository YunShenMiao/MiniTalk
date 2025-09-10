/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:35:15 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:49:40 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// is used to set a block of memory to zero
void	*ft_bzero(void *str, size_t nbyte)
{
	size_t			count;
	unsigned char	*temp;

	count = 0;
	temp = str;
	while (count < nbyte)
	{
		temp[count] = 0;
		count++;
	}
	return (str);
}
