/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:26:35 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/16 14:54:50 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* void signal_handler(int signum)
{
    
} */

int main()
{
    pid_t pid;

    pid = getpid();
    ft_printf("Hi there! Server initialized. The PID is: %d\n", pid);
    while (1)
    {
        
    }
    /*
    - create endless loop so that the server can receive signals at any time;
    - receive signals;
    - decrypt signals: If SIGUSR1 do this. IF SIGUSR2 do that;
    */
    
    return (0);
}