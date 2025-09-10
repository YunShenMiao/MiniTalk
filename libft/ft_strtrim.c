/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:39:13 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:54:42 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_beg(char const *s1, char const *set)
{
	int	begin;
	int	count;

	begin = 0;
	count = 0;
	while (set[count] != '\0')
	{
		if (s1[begin] == set[count])
		{
			begin++;
			count = -1;
		}
		count++;
	}
	return (begin);
}

static int	ft_end(char const *s1, char const *set)
{
	int	end;
	int	count;
	int	sstrl;

	end = 0;
	count = 0;
	sstrl = ft_strlen(s1);
	while (set[count] != '\0')
	{
		if (s1[sstrl - 1] == set[count])
		{
			end++;
			count = -1;
			sstrl--;
		}
		count++;
	}
	return (end);
}

static char	*ft_trim_str(char const *s1, char *res, int begin, int strls1)
{
	int	count;
	int	begin2;

	count = 0;
	begin2 = begin;
	while (count < (strls1 - begin2))
	{
		res[count] = s1[begin];
		count++;
		begin++;
	}
	res[count] = '\0';
	return (res);
}

// trims certain set of characters from end and 
//beginning of string and returns trimmed str
char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	char	*res;
	int		strls1;

	strls1 = ft_strlen(s1);
	begin = ft_beg(s1, set);
	if (*s1 == '\0' || begin == strls1)
	{
		res = malloc(1);
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	end = ft_end(s1, set);
	res = malloc((strls1 - end - begin + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res = ft_trim_str(s1, res, begin, (strls1 - end));
	return (res);
}
