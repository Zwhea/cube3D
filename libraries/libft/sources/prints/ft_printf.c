/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:06:24 by twang             #+#    #+#             */
/*   Updated: 2023/07/12 13:58:38 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	base_conv(va_list list, char c)
{
	ssize_t	size;

	size = 0;
	if (c == 'c')
		return (ft_putchar_fd(va_arg(list, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(list, char *), 1));
	else if (c == 'p')
	{
		size = ft_putstr_fd("0x", 1);
		size += (ft_putnbr_base((size_t)va_arg(list, long long int), \
																HEXA_LOW, 1));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(list, int), 1));
	else if (c == 'u')
		return (ft_putnbr_unsigned_fd(va_arg(list, unsigned int), 1));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(list, unsigned int), HEXA_LOW, 1));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(list, unsigned int), HEXA_UP, 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	size_t	i;
	size_t	size;

	va_start(list, str);
	i = 0;
	size = 0;
	if (write (1, 0, 0))
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
			size += base_conv(list, str[++i]);
		else
			size += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(list);
	return (size);
}
