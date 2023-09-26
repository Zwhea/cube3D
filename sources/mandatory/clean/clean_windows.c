/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:43:55 by twang             #+#    #+#             */
/*   Updated: 2023/09/26 13:51:04 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

#ifndef MACOS

int	clean(t_game *g)
{
	printf(RED"closing program\n"END);
	clean_maps(g);
	clean_textures(g);
	if (g->window)
		mlx_destroy_window(g->mlx, g->window);
	if (g->mlx)
		mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(0);
}

#else

int	clean(t_game *g)
{
	printf(RED"closing program\n"END);
	clean_maps(g);
	clean_textures(g);
	if (g->window)
		mlx_destroy_window(g->mlx, g->window);
	free(g->mlx);
	exit(0);
}

#endif