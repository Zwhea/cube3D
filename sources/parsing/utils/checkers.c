/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:35:51 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/25 16:18:04 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	is_this_first_mistake(t_game *g, bool is_warning)
{
	if (g->map.error.is_valid == false)
	{
		program();
		if (is_warning == true)
			warning();
		else
			error();
		g->map.error.is_valid = true;
	}
}

int	is_textures_charset(char c)
{
	
	return (0);
}

int	is_colors_charset(char c)
{
	
	return (0);
}

int	is_map_charset(char c)
{
	
	return (0);
}
