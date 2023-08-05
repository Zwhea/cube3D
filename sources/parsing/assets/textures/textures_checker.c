/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:05:36 by twang             #+#    #+#             */
/*   Updated: 2023/08/05 14:01:51 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	textures_checker(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4 - 1)
	{
		if (i < 4 - 1 && !(g->textures.walls[i].sprite))
		{
			ft_error(g, false, false, " issue with items's textures\n");
			clean(g);
		}
		i++;
	}
}
