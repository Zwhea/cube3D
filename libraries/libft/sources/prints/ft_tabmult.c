/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 00:04:20 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/30 00:07:21 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabmult(int nb)
{
	int result;
	int i;

	i = 1;
	result = 0;
	while (i < 10)
	{
		result = i * nb;
		ft_putstr_fd("1 x ", 2);
		ft_putnbr_fd(nb, 2);
		ft_putstr_fd(" = ", 2);
		ft_putnbr_fd(result, 2);
		write (2, "\n", 1);
		i++;
	}
}
