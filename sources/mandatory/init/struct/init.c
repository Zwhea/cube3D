/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:48:31 by twang             #+#    #+#             */
/*   Updated: 2023/08/24 14:21:25 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	init_struct(t_game *g)
{
	ft_bzero((void *)g, sizeof(t_game));
	ft_bzero((void *)&g->file, sizeof(t_file));
	ft_bzero((void *)&g->map, sizeof(t_map));
	ft_bzero((void *)&g->player, sizeof(t_player));
	ft_bzero((void *)&g->window_size, sizeof(t_vector));
	ft_bzero((void *)&g->textures, sizeof(t_tex));
	ft_bzero((void *)&g->color, sizeof(t_color));
	ft_bzero((void *)&g->draw, sizeof(t_draw));
}

void	set_vector(t_vector *vector, int x, int y)
{
	vector->x = x;
	vector->y = y;
}


