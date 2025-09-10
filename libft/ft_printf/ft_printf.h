/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:09:34 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/12 16:28:48 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_formatcont(const char *format, va_list args, int count);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_puthexs(int x, int count, char *res, int ret);
int	ft_puthexb(int x, int count, char *res, int ret);
int	ft_puthex(int x, const char *format);
int	ft_putadr(void *ptr);
int	ft_putunsignedint(unsigned int n);
int	ft_strlens(char *stri);
int	ft_adrhelp(unsigned long x, int count, char *res, int nb);

#endif