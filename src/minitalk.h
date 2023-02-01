/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:53:51 by druina            #+#    #+#             */
/*   Updated: 2023/02/01 18:55:29 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/src/libft.h"
# include <signal.h>
# include <unistd.h>

static void	handler(int signal);
static void	send_bit_by_bit(int pid, char c);
static char	*append_to_a_string(char *message, char c);

#endif
