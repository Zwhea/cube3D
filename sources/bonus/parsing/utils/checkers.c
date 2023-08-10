/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:35:51 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/04 19:44:20 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	is_this_first_mistake(t_game *g, bool is_warning)
{
	if (g->map.error == false)
	{
		program();
		if (is_warning == true)
			warning();
		else
			error();
		g->map.error = true;
	}
}
