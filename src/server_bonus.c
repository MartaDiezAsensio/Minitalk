/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:58:37 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/09/22 20:59:43 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	c = 0;
	char		chr;

	(void)context;
	if (sig == SIGUSR1)
		c = c | (0x01 << bit);
	if (++bit == 8)
	{
		chr = c;
		write(1, &chr, 1);
		bit = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	pid = getpid();
	ft_printf("PID = %d\n", pid);
	sa.sa_sigaction = &sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	while (1)
		sleep(1);
	return (0);
}
