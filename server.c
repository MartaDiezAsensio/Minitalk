/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:58:37 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/07 21:31:41 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	bit = 0;
static int	c = 0;

void	sig_handler(int sig)
{	
	static int	bit = 0;
	static int	c = 0;
	
	if (sig == SIGUSR1)
		c = c | (0x01 << bit);
	if (++bit == 8)
	{
		printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 1)
	{
		printf("Error\n");
		return (1);
	}
	pid = getpid();
	printf("PID = %d\n", pid);
	
	struct sigaction sa;

	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		printf("Error");
		return (1);
	}

	while (1)
		sleep(1);
	return (0);
}