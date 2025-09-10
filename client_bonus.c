/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:56:16 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/15 21:00:18 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	signal_received(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message received. Love uuu too <3\n");
	exit(0);
}

int	send_eol(int pid)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		if (kill(pid, SIGUSR1) == -1)
			return (ft_printf("error: failed to send termination signal :0\n"),
				-1);
		usleep(120);
		count--;
	}
	return (0);
}

int	send_signals(int pid, char *argv)
{
	int	count;
	int	i;

	i = -1;
	while (argv[++i] != '\0')
	{
		count = 8;
		while (--count >= 0)
		{
			if (argv[i] & (1 << count))
			{
				if (kill(pid, SIGUSR2) == -1)
					return (ft_printf("error: failed to send SIGUSR2\n"), -1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					return (ft_printf("error: failed to send SIGUSR1\n"), -1);
			}
			usleep(120);
		}
	}
	if (send_eol(pid) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	action;
	int					pid;

	if (argc != 3)
		return (ft_printf("error: invalid amount of arguments :o\n"), 1);
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
		return (ft_printf("error: invalid PID :o\n"), 1);
	if (argv[2][0] == '\0')
		return (ft_printf("error: invalid input string :o\n", 1));
	action.sa_handler = signal_received;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		return (ft_printf("error: sigaction failed :o\n"), 1);
	if (send_signals(pid, argv[2]) == -1)
		return (1);
	pause();
	return (0);
}
