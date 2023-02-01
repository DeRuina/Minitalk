/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:23:24 by druina            #+#    #+#             */
/*   Updated: 2023/02/01 11:17:06 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

static void	handler(int signal)
{
	static char	c;
	static int	count;
	static int	mask;
	static char	*message;

	c = 0;
	count = 0;
	mask = 0b10000000;
	message = NULL;
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
			message = NULL;
		}
		c = 0;
		count = 0;
		mask = 0b10000000;
	}
}

int	main(void)
{
	ft_printf("Hey, beautiful person, PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, &handler);
		signal(SIGUSR2, &handler);
		pause();
	}
	return (0);
}
