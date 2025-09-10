/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:45:08 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:51:40 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// searches for first ocurrence of character
// in nbytes of string pointed to
// returns pointer to matching byte or NULL
void	*ft_memchr(const void *str, int c, size_t nbytes)
{
	unsigned char	*strt;

	strt = (unsigned char *)str;
	while (nbytes)
	{
		if (*strt == (unsigned char)c)
			return (strt);
		strt++;
		nbytes--;
	}
	return (NULL);
}
