/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:24:02 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:53:37 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//allocates str and joins s1 and s2 and stores
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		count;
	int		count2;

	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	count = 0;
	count2 = 0;
	while (s1[count] != '\0')
	{
		join[count] = s1[count];
		count++;
	}
	while (s2[count2] != '\0')
	{
		join[count] = s2[count2];
		count++;
		count2++;
	}
	join[count] = '\0';
	return (join);
}
