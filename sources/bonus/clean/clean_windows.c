/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:43:55 by twang             #+#    #+#             */
/*   Updated: 2023/09/05 09:53:05 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	clean_legend(t_game *g)
{
	printf(RED"closing legend\n"END);
	mlx_destroy_window(g->mlx, g->legend_window);
	g->legend_window = NULL;
	return (0);
}

#ifndef MACOS

int	clean(t_game *g)
{
	printf(RED"closing program\n"END);
	clean_maps(g);
	clean_textures(g);
	if (g->window)
		mlx_destroy_window(g->mlx, g->window);
	if (g->legend_window)
		clean_legend(g);
	if (g->mlx)
		mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(0);
}

#else

int	clean(t_game *g)
{
	printf(RED"closing program\n"END);
	if (g->file.fd)
		close(g->file.fd);
	clean_maps(g);
	clean_textures(g);
	if (g->window)
		mlx_destroy_window(g->mlx, g->window);
	if (g->legend_window)
		clean_legend(g);
	free(g->mlx);
	exit(0);
}

#endif