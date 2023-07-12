/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdebug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:34:00 by mmosca            #+#    #+#             */
/*   Updated: 2023/07/12 14:29:35 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdebug(int line, char *file)
{
	dprintf(2, PURPLE"%s : %d "END, file, line);
}

void	ft_putidebug(int x, int line, char *file)
{
	dprintf(2, PURPLE"%s : %d "END"%i\n", file, line, x);
}

void	ft_putsdebug(const char *x, int line, char *file)
{
	dprintf(2, PURPLE"%s : %d "END"%s\n", file, line, x);
}
