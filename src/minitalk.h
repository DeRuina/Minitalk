/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:53:51 by druina            #+#    #+#             */
/*   Updated: 2023/02/02 09:50:14 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/src/libft.h"
# include <signal.h>
# include <unistd.h>

static void	signal_handler(int signal, siginfo_t *info, void *context);
static char	*append_to_a_string(char *message, char c);
static void	send_bit_by_bit(pid_t pid, char c);
static void	signal_received(int signal);

#endif
