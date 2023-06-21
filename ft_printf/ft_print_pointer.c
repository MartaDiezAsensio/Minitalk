/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:32:50 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/24 18:49:05 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_pointer_hexa(unsigned long num)
{
	int	length;

	length = 0;
	while (num)
	{
		num /= 16;
		length++;
	}
	return (length);
}

int	ft_print_pointer_hexa(unsigned long num)
{
	char	*print;
	int		i;

	i = size_pointer_hexa(num);
	print = malloc(sizeof(char) * (i + 1));
	if (!print)
		return (-1);
	print[i] = '\0';
	while (num != 0 && i-- >= 0)
	{
		if ((num % 16) < 10)
			print[i] = (num % 16) + '0';
		else
			print[i] = (num % 16) + 'a' - 10;
		num = num / 16;
	}
	i = ft_putstr(print);
	free(print);
	return (i);
}

int	ft_print_pointer(unsigned long num)
{
	int	i;
	int	ret;

	i = 2;
	if (ft_putstr("0x") == -1)
		return (-1);
	if (num == 0)
		ret = ft_putchar('0');
	else
		ret = ft_print_pointer_hexa(num);
	if (ret == -1)
		return (-1);
	i += ret;
	return (i);
}
