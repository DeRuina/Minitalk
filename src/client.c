/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:23:39 by druina            #+#    #+#             */
/*   Updated: 2023/02/02 10:00:53 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/src/libft.h"
# include <signal.h>
# include <unistd.h>

static void	signal_received(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("signal recieved\n");
}

static void	send_bit_by_bit(pid_t pid, char c)
{
	int	i;
	int	mask;

	mask = 0b10000000;
	i = 0;
	while (i < 8)
	{
		if ((c & mask) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		mask = mask >> 1;
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	received;

	received.__sigaction_u.__sa_handler = signal_received;
	received.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &received, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 0 || !pid)
			return (ft_printf("Wrong PID, try again\n"));
		while (*argv[2])
		{
			send_bit_by_bit(pid, *argv[2]);
			argv[2]++;
		}
		send_bit_by_bit(pid, '\0');
	}
	else
		return (ft_printf("Hey ASSHOLE,you need 2 arguments,try again\n"));
	return (0);
}
