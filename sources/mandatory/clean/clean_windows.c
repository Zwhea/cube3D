/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:43:55 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 15:27:03 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#ifndef MACOS

int	clean(t_game *g)
{
	printf(RED"closing program\n"END);
	if (g->file.fd)
		close_file(g->file.fd);
	clean_maps(g);
	clean_textures(g);
	if (g->draw.img)
		mlx_destroy_image(g->mlx, g->draw.img);
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
	if (g->file.fd)
		close(g->file.fd);
	clean_maps(g);
	clean_textures(g);
	if (g->draw.img)
		mlx_destroy_image(g->mlx, g->draw.img);
	if (g->window)
		mlx_destroy_window(g->mlx, g->window);
	free(g->mlx);
	exit(0);
}

#endif