/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:58:21 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/07 21:37:25 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	send_bit(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(500);
}

void	send_chr(int pid, char ch)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		send_bit(pid, (ch >> bit) & 0x01);
		bit++;
	}
}

void	send_str(int pid, const char	*str)
{
	int	i;
	int	len;

	i = 0;
	len = strlen(str);
	while (i < len)
	{
		send_chr(pid, str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	pid = atoi(argv[1]);

	send_str(pid, argv[2]);

	return (0);
}