/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:43:55 by twang             #+#    #+#             */
/*   Updated: 2023/08/10 12:01:04 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	clean_mini_map(t_game *g)
{
	printf(RED"closing mini map\n"END);
	mlx_destroy_window(g->mlx, g->map_window);
	g->map_window = NULL;
	return (0);
}

int	clean_legend(t_game *g)
{
	printf(RED"closing legend\n"END);
	mlx_destroy_window(g->mlx, g->legend_window);
	g->legend_window = NULL;
	return (0);
}

int	clean(t_game *g)
{
	printf(RED"closing program\n"END);
	if (g->map.map)
		clean_map(g);
	clean_textures(g);
	if (g->window)
		mlx_destroy_window(g->mlx, g->window);
	if (g->map_window)
		clean_mini_map(g);
	if (g->legend_window)
		clean_legend(g);
	// if (g->mlx)
	// 	mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(0);
}