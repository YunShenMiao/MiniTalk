/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:16:57 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:52:53 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//refers to first occurence of c in str 
char	*ft_strchr(char *str, int c)
{
	char	ret;

	ret = (char)c;
	while (*str)
	{
		if (*str == ret)
			return ((char *)str);
		str++;
	}
	if (ret == '\0')
		return ((char *)str);
	return (0);
}
