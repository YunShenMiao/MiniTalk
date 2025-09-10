/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:50:05 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/14 17:55:26 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_formatcont(const char *format, va_list args, int count)
{
	int	check;

	if (*format == 'c')
		check = count + ft_putchar(va_arg(args, int));
	else if (*format == 's')
		check = count + ft_putstr(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		check = count + ft_putnbr(va_arg(args, int));
	else if (*format == 'x' || *format == 'X')
		check = count + ft_puthex(va_arg(args, int), format);
	else if (*format == 'p')
		check = count + ft_putadr(va_arg(args, void *));
	else if (*format == 'u')
		check = count + ft_putunsignedint(va_arg(args, unsigned int));
	else if (*format == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		check = count + 1;
	}
	else
		return (-1);
	if (check < count)
		return (-1);
	return (count = check);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			count = ft_formatcont(format, args, count);
			if (count == -1)
				return (-1);
		}
		else if (*format)
		{
			if (write(1, &(*format), 1) == -1)
				return (-1);
			count++;
		}
		format++;
	}
	return (va_end(args), count);
}
