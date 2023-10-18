/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_switchman.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:40:26 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/04 13:55:59 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	asset_switchman(t_game *g, char *line)
{
	int					i;
	int					j;
	const t_lst_assets	list[] = {{NULL, &handle_no_asset}, \
								{"NO ", &handle_north_texture}, \
								{"SO ", &handle_south_texture}, \
								{"WE ", &handle_west_texture}, \
								{"EA ", &handle_east_texture}, \
								{"F ", &handle_floor_color}, \
								{"C ", &handle_ceiling_color}};

	i = 0;
	j = 1;
	i += ft_skipwhitespace(i, line);
	while (j < 7)
	{
		if (!(ft_strncmp(&line[i], list[j].asset, ft_strlen(list[j].asset))))
			return (list[j].func(g, line));
		j++;
	}
	return (list[0].func(g, line));
}
