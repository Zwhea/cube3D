/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:12:53 by twang             #+#    #+#             */
/*   Updated: 2023/08/03 14:13:02 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isempty(char *s)
{
	int	i;

	i = 0;
	while (s[i] && ft_iswhitespace(s[i]))
		i++;
	if (s[i])
		return (0);
	return (1);
}
