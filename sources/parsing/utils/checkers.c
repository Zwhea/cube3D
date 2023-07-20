/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:35:51 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/20 21:10:55 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	is_this_first_error(t_game *g)
{
	if (g->map.error.is_valid == true)
	{
		error();
		g->map.error.is_valid = false;
	}
}
