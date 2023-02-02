/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:23:24 by druina            #+#    #+#             */
/*   Updated: 2023/02/02 10:00:48 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/src/libft.h"
# include <signal.h>
# include <unistd.h>

static char	*append_to_a_string(char *message, char c)
{
	char	*answer;
	char	c_to_str[2];

	c_to_str[0] = c;
	c_to_str[1] = '\0';
	answer = ft_strjoin(message, c_to_str);
	if (message)
		free(message);
	return (answer);
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	count = 0;
	static int	mask = 0b10000000;
	static char	*message = NULL;

	(void)context;
	if (signal == SIGUSR1)
		c = c | mask;
	mask = mask >> 1;
	count++;
	if (count == 8)
	{
		message = append_to_a_string(message, c);
		if (c == '\0')
		{
			ft_printf("%s\n", message);
			kill(info->si_pid, SIGUSR1);
			message = NULL;
		}
		c = 0;
		count = 0;
		mask = 0b10000000;
	}
}

int	main(void)
{
	struct sigaction	print;

	ft_printf("Hey, beautiful person, PID is: %d\n", getpid());
	print.__sigaction_u.__sa_sigaction = signal_handler;
	print.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &print, NULL);
		sigaction(SIGUSR2, &print, NULL);
		pause();
	}
	return (0);
}
