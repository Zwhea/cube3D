/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfromcharset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:53:05 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/29 23:48:03 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isfromcharset(char c, char *base)
{
	while (*base && c != *base)
		base++;
	if (*base == c)
		return (1);
	return (0);
}
