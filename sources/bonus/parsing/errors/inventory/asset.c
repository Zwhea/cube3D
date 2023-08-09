/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:02:59 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/09 16:10:58 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	_wrong_asset(t_game *g)
{
	ft_error(g, false, false, WRONG_ASSET);
}

void	_wrong_texture(t_game *g)
{
	ft_error(g, false, false, WRONG_TEXTURE);
	clean(g);
}

void	_wrong_color(t_game *g)
{
	ft_error(g, false, false, WRONG_COLOR);
	clean(g);
}
