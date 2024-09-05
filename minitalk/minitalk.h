/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:29:27 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/30 11:16:34 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "libft/libft.h"

void	bytes_to_char(const char *str);
void	bytes_builder(char c, pid_t client_pid);
void	signal_handler(int signum, siginfo_t *info, void *context);
void	ack_handler(int signum);
void	*char_to_bits(char c, char *binary);
void	handle_message(int pid, const char *str);
void	check_error_arg(char **argv, int pid);
void	check_error_signal(char *binary, int j, int pid);

#endif