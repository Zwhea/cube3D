/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:49:57 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/29 23:50:12 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base(char c, int base_size)
{
	char *base_lowcase = "0123456789abcdef";
	char *base_upcase = "0123456789ABCDEF";
	int  i = 0;

	while (i < base_size)
	{
		if (c == base_lowcase[i] || c == base_upcase[i])
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int nb = 0;
	int negativ = 0;
	int	i = 0;
	
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negativ = 1;
		i++;
	}
	while (base(str[i], str_base) != -1)
	{
		nb = nb * str_base;
		nb = nb + base(str[i], str_base);
		i++;
	}
	if (negativ)
		return (-nb);
	return (nb);
}
