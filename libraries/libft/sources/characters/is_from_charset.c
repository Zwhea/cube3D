/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_from_charset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:53:05 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/12 13:55:01 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_from_charset(int c, char *base)
{
	while (*base && c != *base)
		base++;
	if (*base == c)
		return (1);
	return (0);
}
