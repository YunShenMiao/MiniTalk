/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:32:20 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/12 16:30:31 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

int	ft_strlens(char *stri)
{
	int	count;

	count = 0;
	while (stri[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	ft_putchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[count] != '\0')
	{
		if (write(1, &s[count], 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	else if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr((n / 10));
		if (count == -1)
			return (-1);
	}
	if (write(1, &((char){'0' + n % 10}), 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putunsignedint(unsigned int n)
{
	char	c;
	int		count;
	int		fu;

	count = 0;
	if (n >= 10)
	{
		fu = ft_putunsignedint((n / 10));
		if (fu == -1)
			return (-1);
		count += fu;
	}
	c = n % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}
