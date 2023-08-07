/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:19:40 by twang             #+#    #+#             */
/*   Updated: 2023/08/07 12:07:13 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	map_checker(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.map[++i])
	{
		if (ft_isempty(g->map.map[i]))
			error_switchman(g, wrong_map);
		j = -1;
		while (g->map.map[i][++j])
		{
			if (g->map.map[i] && !ft_strchr(MAP_CHARSET, g->map.map[i][j]))
			{
				printf(RED"-%c-\n"END, g->map.map[i][j]);
				error_switchman(g, wrong_char);
			}
		}
	}
}
