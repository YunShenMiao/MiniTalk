/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:56:16 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/13 17:09:18 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

int	main(int argc, char *argv[])
{
	int count;
	int i;
	int pid;

	i = 0;
	pid = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			count = 7;
			while (count >= 0)
			{
				if (argv[2][i] & (1 << count))
				{
				ft_printf("Sending SIGUSR2 for bit %d\n", count); // Debug print
					kill(pid, SIGUSR2);
				}
				else
				{
					ft_printf("Sending SIGUSR1 for bit %d\n", count); // Debug print
					kill(pid, SIGUSR1);
				}
				usleep(2000);
				count--;
			}
			i++;
		}
	}
return(0);
}

//add stop-condition