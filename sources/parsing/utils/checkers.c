/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:35:51 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/22 12:37:23 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	is_this_first_mistake(t_game *g, bool is_error, bool is_warning)
{
	if (g->map.error.is_valid == false)
	{
		program();
		if (is_error == true)
			error();
		if (is_warning == true)
			warning();
		g->map.error.is_valid = true;
	}
}
