/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:48:31 by twang             #+#    #+#             */
/*   Updated: 2023/08/07 14:32:06 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	init_struct(t_game *g)
{
	ft_bzero((void *)g, sizeof(t_game));
	ft_bzero((void *)&g->file, sizeof(t_file));
	ft_bzero((void *)&g->map, sizeof(t_map));
	ft_bzero((void *)&g->player, sizeof(t_player));
	ft_bzero((void *)&g->textures, sizeof(t_tex));
}

void	set_vector(t_vector *vector, int x, int y)
{
	vector->x = x;
	vector->y = y;
}