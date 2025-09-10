/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:11:41 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/12 16:29:43 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_adrhelp(unsigned long x, int count, char *res, int nb)
{
	while (x > 0)
	{
		nb = x % 16;
		if (nb < 10)
			res[count++] = nb + '0';
		else
			res[count++] = nb - 10 + 'a';
		x = x / 16;
	}
	res[count] = '\0';
	while (--count >= 0)
		if (write(1, &res[count], 1) == -1)
			return (-1);
	return (ft_strlens(res));
}

int	ft_puthexb(int x, int count, char *res, int nb)
{
	unsigned int	xx;

	if (x < 0)
		xx = (unsigned int)x;
	else
		xx = x;
	while (xx > 0)
	{
		nb = xx % 16;
		if (nb < 10)
			res[count++] = nb + '0';
		else
			res[count++] = nb - 10 + 'A';
		xx = xx / 16;
	}
	res[count] = '\0';
	while (--count >= 0)
		if (write(1, &res[count], 1) == -1)
			return (-1);
	return (ft_strlens(res));
}

int	ft_puthexs(int x, int count, char *res, int nb)
{
	unsigned int	xx;

	if (x < 0)
		xx = (unsigned int)x;
	else
		xx = x;
	while (xx > 0)
	{
		nb = xx % 16;
		if (nb < 10)
			res[count++] = nb + '0';
		else
			res[count++] = nb - 10 + 'a';
		xx = xx / 16;
	}
	res[count] = '\0';
	while (--count >= 0)
		if (write(1, &res[count], 1) == -1)
			return (-1);
	return (ft_strlens(res));
}

int	ft_puthex(int x, const char *format)
{
	char	res[100];
	int		count;
	int		ret;
	int		nb;

	count = 0;
	ret = 0;
	nb = 0;
	if (x == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		if (write(1, &res[0], 1) == -1)
			return (-1);
		return (1);
	}
	else
	{
		if (*format == 'x')
			ret = ft_puthexs(x, count, res, nb);
		else if (*format == 'X')
			ret = ft_puthexb(x, count, res, nb);
	}
	return (ret);
}

int	ft_putadr(void *ptr)
{
	unsigned long	adr;
	char			res[100];
	int				count;
	int				nb;
	int				countret;

	count = 0;
	nb = 0;
	adr = (unsigned long)ptr;
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (adr == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		if (write(1, &res[0], 1) == -1)
			return (-1);
		return (3);
	}
	else
		countret = ft_adrhelp(adr, count, res, nb);
	return (countret + 2);
}
