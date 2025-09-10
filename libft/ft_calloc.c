/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:19:29 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:49:48 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// allocates specified amount of memory and initializes it to 0
void	*ft_calloc(size_t nitems, size_t size)
{
	char	*mao;

	mao = malloc(nitems * size);
	if (mao == NULL)
		return (NULL);
	return (ft_bzero(mao, nitems * size));
}
