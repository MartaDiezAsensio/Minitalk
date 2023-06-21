/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:30:37 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/31 18:03:26 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dig_hex(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

static int	print_digit2(unsigned int digit, int i)
{
	int	ret;

	if (digit <= 9)
		ret = ft_putchar(digit + '0');
	else
		ret = ft_putchar(digit + 'A' - 10);
	i++;
	return (ret);
}

static int	recursive_hex2(unsigned int nb, int i)
{
	int	ret;

	ret = 0;
	if (nb >= 16)
	{
		ret = recursive_hex2(nb / 16, i++);
		if (ret == -1)
			return (-1);
		ret += recursive_hex2(nb % 16, i++);
		if (ret == -1)
			return (-1);
	}
	else
	{
		ret = print_digit2(nb, i++);
		if (ret == -1)
			return (-1);
	}
	return (i);
}

int	ft_print_hex2(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		return (write(1, "0", 1));
		i++;
	}
	else
		if (recursive_hex2(nb, i) == -1)
			return (-1);
	return (ft_dig_hex(nb));
}
