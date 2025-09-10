/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:26:28 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:52:44 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strnbr(char const *s, char c)
{
	int	count;
	int	strn;

	count = 0;
	strn = 0;
	while (s[count] != '\0')
	{
		if (s[count] != c)
		{
			strn++;
			while (s[count] != c && s[count] != '\0')
			{
				count++;
			}
		}
		if (s[count] != '\0')
			count++;
	}
	return (strn);
}

static char	*ft_stringsi(char const *s, char c, int start)
{
	char	*str;
	int		strl;
	int		count;

	strl = 0;
	count = 0;
	while (s[strl + start] != '\0' && s[strl + start] != c)
	{
		strl++;
	}
	str = malloc((strl + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[start] != c && s[start] != '\0' && count < strl)
	{
		str[count] = s[start];
		start++;
		count++;
	}
	str[count] = '\0';
	return (str);
}

static void	ft_free(char **res, int ind)
{
	int	count;

	count = 0;
	while (ind >= count)
	{
		free(res[ind]);
		ind--;
	}
	free(res);
}

static int	ft_array(char **res, char const *s, char c, int strnbr)
{
	int	start;
	int	ind;

	start = 0;
	ind = 0;
	while (s[start] != '\0' && ind < strnbr)
	{
		while (s[start] == c)
			start++;
		if (s[start] != c && s[start] != '\0')
		{
			res[ind] = ft_stringsi(s, c, start);
			if (res[ind] == NULL)
				return (ind);
			while (s[start] != c && s[start] != '\0')
				start++;
		}
		ind++;
	}
	return (-1);
}

//splits string at delimeter char and allocates
// and returns arr
char	**ft_split(char const *s, char c)
{
	char	**res;
	int		strnbr;
	int		check;

	strnbr = ft_strnbr(s, c);
	res = malloc((strnbr + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	check = ft_array(res, s, c, strnbr);
	if (check >= 0)
	{
		ft_free(res, check);
		return (NULL);
	}
	res[strnbr] = NULL;
	return (res);
}
