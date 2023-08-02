/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipwhitespaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:14:18 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/02 22:18:48 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_skipwhitespace(int savepoint, char *s)
{
	while (s[savepoint] && ft_iswhitespace(s[savepoint]))
		savepoint++;
	return (savepoint);
}
