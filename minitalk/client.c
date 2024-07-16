/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:33:12 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/16 15:02:11 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *char_to_bits(char c)
{
    int num;
    char *binary;
    int i = 7;
    
    num = c;
    if(!num)
        return (ft_strdup(""));
    binary = (char *)malloc(sizeof(char) * 9);
    if(!binary)
        return (NULL);
    while (num)
    {
        binary[i] = (num % 2) + 48;
        num /= 2;
        i--;
    }
    while (i >= 0)
    {
        binary[i] = '0';
        i--;
    }
    return (binary);    
}

void    handle_message(int pid, char *str)
{
    int i;
    char *binary;

    i = 0;
    if(!str)
        return ;
    while (str[i])
    {
        binary = (char *)malloc(sizeof(char) * 9);
        if (!binary)
            return ;
        binary = char_to_bits(str[i]);
        while(*binary)
        {
            if(*binary == '1')
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
        }
        free(binary);
        i++;
    }
    if (!str[i])
        kill(pid, 0);
}

int main(int argc, char **argv)
{
    int pid;
    
    if (argc != 3)
    {
        ft_printf("Error! This is how the program should be executed:\n");
        ft_printf("    ./client <PID NUMBER> <MESSAGE>\n");
        exit(-1);
    }
    pid = ft_atoi(argv[1]);
    handle_message(pid, argv[2]);
    return (0);
}