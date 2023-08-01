/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:07:37 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/01 16:31:47 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	which_asset(t_game *g, char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	if (ft_strncmp(&line[i], "NO ", 3) == 0)
		return (get_assets(g, line, north_texture));
	else if (ft_strncmp(&line[i], "SO ", 3) == 0)
		return (get_assets(g, line, south_texture));
	else if (ft_strncmp(&line[i], "WE ", 3) == 0)
		return (get_assets(g, line, west_texture));
	else if (ft_strncmp(&line[i], "EA ", 3) == 0)
		return (get_assets(g, line, east_texture));
	else if (ft_strncmp(&line[i], "F ", 2) == 0)
		return (get_assets(g, line, floor_color));
	else if (ft_strncmp(&line[i], "C ", 2) == 0)
		return (get_assets(g, line, ceiling_color));
	return (get_assets(g, line, no_asset));
}
