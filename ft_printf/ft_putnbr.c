/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:21:15 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/24 18:51:45 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putdigits(int n)
{
	int	i;
	int	ret;

	i = 0;
	if (n / 10)
	{
		ret = ft_putdigits(n / 10);
		if (ret == -1)
			return (-1);
		i += ret;
		ret = ft_putdigits(n % 10);
		if (ret == -1)
			return (-1);
		i += ret;
	}
	else
	{
		if (ft_putchar('0' + n) == -1)
			return (-1);
		i++;
	}	
	return (i);
}

int	ft_putnbr(int n )
{
	int	ret;
	int	length;

	length = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		length = 1;
		n *= -1;
	}
	ret = ft_putdigits(n);
	if (ret == -1)
		return (-1);
	return (length + ret);
}
