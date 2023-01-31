/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:23:24 by druina            #+#    #+#             */
/*   Updated: 2023/01/31 16:42:45 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int signal)
{

}

int main(void)
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