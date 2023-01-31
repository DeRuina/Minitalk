/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:23:39 by druina            #+#    #+#             */
/*   Updated: 2023/01/31 16:34:04 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit_by_bit(int pid, char c)
{
	int	i;
  int mask;

  mask = 0b10000000;
	i = 0;
	while (i < 8)
	{
		if (c & mask != 0)
			kill(pid, SIGUSR1);
		else
      kill(pid, SIGUSR2);
		mask = mask >> 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 0)
			return (ft_printf("Wrong PID, try again\n"));
		while (*argv[2])
		{
			send_bit_by_bit(pid, *argv[2]);
			argv[2]++;
		}
	}
	else
		return (ft_printf("Hey ASSHOLE, instructions said 2 arguments,try again\n"));

	return (0);
}