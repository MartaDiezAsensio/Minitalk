/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:21:14 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/06 21:52:20 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] + '0');
		i++;
	}
	return (neg * num);
}

/*
This function send the binary representation of the character c to the target (PID introduced).
*/
/*
Variable bit keeps track of the current bit position beeing processed. 
Function iterates 8 times, representing the 8 bits in the binary representation of a character (byte).
*/
/*
Inside the loop, the function checks if the current bit in c is set to 1.
It does this by performing a bitwise AND operation between c and a mask reated by shifting the value 
0x01 to the left by bit positions.
*/
/*
If the current bit is set (i.e., the result of the bitwise operation AND is zero), the function sends the 
SIGUSR2 signal to the target audience using kill(pid, SIGUSR2), which represets a 0.
The waits for the server to receive the signal and process it.
*/
void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

/*
The client takes two parameters: The server's PID and the string to send. 
*/
/*
If we have 3 parameters (argc = 3) means that we have the correct imput (executable + server PID = String to send)
Otherwise we give an error messaage. 
*/
/*
For every character in the string that is entered we call the funtion ft_atob that triggers the signal to server.
*/
int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_atob(pid, argv[2][i]);
			i++;
		}
	}
	else
	{
		printf("%d\n", argc);
		printf("Error\n");
		return (1);
	}
	return (0);
}




//Theory

/*
Bitwise operations
	- Bitwise operations are operations erformed on the individual bits of binary reresentation of numbers.
	These operations manipulate the bits directly, allowing to erform various operations at the bit level.

	The most common bitwise operators are:
		- Bitwise and (&): Compares the corresponfing bits of two numbers and produces a new number where 
		each bit is set if and only if both corresponding bits in the original numbers are set to 1.
		- Bitwise or (|): Compares the correspondig bits of two numbers and produces a new number where each 
		bit is set if either os the bits is set to 1.
		- Also XOR (^) and NOT (~)

	Left Shift (<<): Shifts the bits of a number to the left by a secified number of positions. Is the equivalent
	to multiplying the number by 2 raised to the power of the shift ammount.
	Right Shift (>>): Shifts the bits of a number to the right by a secified number of positions.
	Is the equivalent to dividing the number by two to the power of opositions you waant to move.  
*/

//Example of bitwise operation

/*int	main()
{
	unsigned int	num = 5; // Binary: 00000101

	//Left shift num by 2 positions
	unsigned int	result = num << 2; // Binary: 00010100

	//Now result = 20;
}*/