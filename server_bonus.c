/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:54:48 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/16 14:50:03 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	bitcount;
	static char	str[2097152];
	static int	count;

	(void)context;
	if (signum == SIGUSR2)
		c |= (1 << (7 - bitcount));
	else if (signum == SIGUSR1)
		c &= ~(1 << (7 - bitcount));
	bitcount++;
	if (bitcount == 8)
	{
		str[count] = c;
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			usleep(10);
			kill(info->si_pid, SIGUSR1);
			count = -1;
		}
		count++;
		bitcount = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigaction(SIGUSR1, &action, NULL) == -1 || sigaction(SIGUSR2, &action,
			NULL) == -1)
		return (ft_printf("error: Sigaction failed :o\n"), 1);
	while (1)
		pause();
	return (0);
}
