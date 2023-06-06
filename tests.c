/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:15:27 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/06 21:30:57 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

/*
0x01 (hexadecimal) == 1 (decimal) == 00000001 (binary in 8-bit representation)
*/
/*
The result of (0x01 << bit) is a value where the bit at positioon bit is set to 1 
and the rest od positions are set to 0. THis creates a mask to check the specific bit
position in c.  
*/
/*
(c & (0x01 << bit))
This operation allows us to check the value of a specific bit in c by masking out all 
other bits.
*/

int	main(void)
{
	int	bit = 0;
	int	c = 5;

	while (bit < 8)
	{
		if (c & (0x01 << bit))
			printf("1 ");
		else
			printf("0 ");
		bit++;
	}
}