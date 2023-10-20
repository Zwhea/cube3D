/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:48:31 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 15:22:01 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_struct(t_game *g)
{
	ft_bzero((void *)g, sizeof(t_game));
	ft_bzero((void *)&g->file, sizeof(t_file));
	ft_bzero((void *)&g->map, sizeof(t_map));
	ft_bzero((void *)&g->mini_map, sizeof(t_minimap));
	ft_bzero((void *)&g->player, sizeof(t_player));
	ft_bzero((void *)&g->doors, sizeof(t_door));
	ft_bzero((void *)&g->window_size, sizeof(t_vector));
	ft_bzero((void *)&g->sprites, sizeof(t_sprites));
	ft_bzero((void *)&g->textures, sizeof(t_tex));
	ft_bzero((void *)&g->color, sizeof(t_color));
	ft_bzero((void *)&g->draw, sizeof(t_draw));
	ft_bzero((void *)&g->ray, sizeof(t_raycast));
	ft_bzero((void *)&g->door, sizeof(t_doorcast));
	g->player.diff_pov = 1;
}

void	set_vector(t_vector *vector, int x, int y)
{
	vector->x = x;
	vector->y = y;
}

void	set_vector_f(t_vector_f *vector, float x, float y)
{
	vector->x = x;
	vector->y = y;
}
