/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:35:51 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/21 15:29:20 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	is_this_first_error(t_game *g)
{
	if (g->map.error.is_valid == false)
	{
		ft_dprintf(2, GREEN BOLD"cub3d: "END);
		error();
		g->map.error.is_valid = true;
	}
}
