/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:37:01 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/31 18:22:10 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_customwrite(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	else
		return (1);
}

static int	ft_formats(va_list args, const char *str)
{
	int	i;

	i = 0;
	if (*(str + 1) == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (*(str + 1) == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (*(str + 1) == 'p')
		i += ft_print_pointer(va_arg(args, unsigned long));
	else if (*(str + 1) == 'd')
		i += ft_putnbr(va_arg(args, int));
	else if (*(str + 1) == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (*(str + 1) == 'u')
		i += ft_putnbr_u(va_arg(args, unsigned int));
	else if (*(str + 1) == 'x')
		i += ft_print_hex(va_arg(args, unsigned int));
	else if (*(str + 1) == 'X')
		i += ft_print_hex2(va_arg(args, unsigned int));
	else if (*(str + 1) == '%')
		i += ft_customwrite();
	else
		return (-1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	va_start(args, str);
	i = 0;
	ret = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			ret = ft_formats(args, str++);
			if (ret == -1)
				return (-1);
		}
		else
		{
			ret = ft_putchar(*str);
			if (ret == -1)
				return (-1);
		}
		i += ret;
		str++;
	}
	return (i);
}
