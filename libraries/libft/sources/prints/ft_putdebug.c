/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdebug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:34:00 by mmosca            #+#    #+#             */
/*   Updated: 2023/07/31 09:28:41 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdebug(int line, char *file)
{
	ft_dprintf(2, PURPLE"%s : %d "END, file, line);
}

void	ft_putidebug(int x, int line, char *file)
{
	ft_dprintf(2, PURPLE"%s : %d "END"%i\n", file, line, x);
}

void	ft_putsdebug(const char *x, int line, char *file)
{
	ft_dprintf(2, PURPLE"%s : %d "END"%s\n", file, line, x);
}

void	ft_print_split(char **file)
{
	int	i;
	
	i = 0;
	ft_dprintf(2, "\n\n");
	while (file[i])
	{
		ft_dprintf(2, PURPLE"%s\n"END, file[i]);
		i++;
	}
	ft_dprintf(2, "\n\n");
}