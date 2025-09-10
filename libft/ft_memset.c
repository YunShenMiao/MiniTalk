/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:25:01 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:52:10 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//fills up to size_t bytes of str with char
void	*ft_memset(void *str, int d, size_t n)
{
	unsigned char	*a;
	size_t			count;
	unsigned char	ex;

	ex = (unsigned char)d;
	a = str;
	count = 0;
	while (count < n)
	{
		a[count] = ex;
		count++;
	}
	return (a);
}
