/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:28:10 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:54:31 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	ret;
	int		strl;

	ret = (char)c;
	strl = ft_strlen(str);
	while (strl >= 0)
	{
		if (str[strl] == ret)
			return ((char *)&str[strl]);
		strl--;
	}
	return (0);
}
