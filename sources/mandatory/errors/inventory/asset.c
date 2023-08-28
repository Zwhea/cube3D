/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:02:59 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/28 13:23:21 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	_wrong_asset(t_game *g)
{
	ft_error(false, WRONG_ASSET);
	clean(g);
}

void	_wrong_texture(t_game *g)
{
	ft_error(false, WRONG_TEXTURE);
	clean(g);
}

void	_wrong_textures(t_game *g)
{
	ft_error(false, WRONG_TEXTURES);
	clean(g);
}

void	_wrong_color(t_game *g)
{
	ft_error(false, WRONG_COLOR);
	clean(g);
}

void	_wrong_colors(t_game *g)
{
	ft_error(false, WRONG_COLORS);
	clean(g);
}
