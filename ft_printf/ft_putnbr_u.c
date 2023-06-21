/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:21:15 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/24 18:53:10 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putdigits(unsigned int n)
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

int	ft_putnbr_u(unsigned int n )
{
	int	ret;

	ret = ft_putdigits(n);
	if (ret == -1)
		return (-1);
	return (ret);
}
