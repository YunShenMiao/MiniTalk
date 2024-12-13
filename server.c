/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:54:48 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/13 17:27:21 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>

// problem with static bitcount 

void	signal_handler(int signum)
{
	static char	c;
	static int	bitcount;

	if (signum == SIGUSR2)
		c |= (1 << (7 - bitcount));
	else if (signum == SIGUSR1)
		c &= ~(1 << (7 - bitcount));
	ft_printf("Received signal: %d, c: %c, bitcount: %d\n", signum, c, bitcount); // Debug print
	bitcount++;
	if (bitcount == 8)
	{
		ft_printf("char: %c\n", c);
		ft_printf("nbrchar: %d\n", c);
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bitcount = 0;
		c = 0;
	}
	usleep(20);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
