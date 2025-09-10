/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:12:30 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:49:58 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_convert(int cneg, int res)
{
	if (cneg == 1)
		res = -res;
	return (res);
}

int	ft_atoi(const char *str)
{
	int	count;
	int	cneg;
	int	res;

	count = 0;
	cneg = 0;
	res = 0;
	while (str[count] == ' ' || str[count] == '\t' || str[count] == '\n'
		|| str[count] == '\v' || str[count] == '\f' || str[count] == '\r')
		count++;
	if (str[count] == '-')
	{
		cneg++;
		count++;
	}
	else if (str[count] == '+')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		res = res * 10 + (str[count] - '0');
		count++;
	}
	return (ft_convert(cneg, res));
}
