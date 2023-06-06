/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:20:56 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/06 21:49:25 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

/*
The fact that the bit++ is outside the loop implies that the character will not try to print until 
8 SIGUSR1 are rceived.
Bit and I need to be static so that the information is not lost everytime a signal is sent. 
*/
/*
ft_btoa will be triggered both when SIGUSR1 and SIGUSR2 are received. But only when SIGUSR1 (that represents 1)
is received it will copy the positive bit to i.
bit either way will be incremented to keep track of the bit position. 
*/
void	ft_btoa(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i = i | (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
	}

}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		printf("Error\n");
		return (1);
	}
	pid = getpid();
	printf("%d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		pause();
	}
	return (0);
}