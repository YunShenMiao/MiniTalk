/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:05:55 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:53:29 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//iterates through s and applies function s to each char
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	count;

	count = 0;
	while (s[count] != '\0')
	{
		f(count, &s[count]);
		count++;
	}
}

/* #include <stdio.h>

void	ft_t(unsigned int x, char *c)
{
	if (x % 2 == 0 && *c >= 97 && *c <= 122)
		*c = *c - 32;
}*/