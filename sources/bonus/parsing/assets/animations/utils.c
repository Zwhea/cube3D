/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:17:51 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 15:35:17 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_image(t_game *g, t_sprites *sprites, bool id_img)
{
	if (id_img)
		sprites->door.img = mlx_xpm_file_to_image(g->mlx, XPM_DOOR, \
							&sprites->door.width, &sprites->door.height);
	else
		sprites->player.img = mlx_xpm_file_to_image(g->mlx, XPM_PLAYER, \
							&sprites->player.width, &sprites->player.height);
}

void	check_img(t_game *g, t_sprites *sprites, bool id_img)
{
	if (id_img)
	{
		if (!(sprites->door.img))
			error_switchman(g, wrong_texture);
	}
	else
	{
		if (!(sprites->player.img))
			error_switchman(g, wrong_texture);
	}
}

void	init_img_settings(t_sprites *sprites, bool id_img)
{
	if (id_img)
		sprites->door.addr = mlx_get_data_addr(sprites->door.img, \
				&sprites->door.bits_per_pixel, &sprites->door.line_length, \
				&sprites->door.endian);
	else
		sprites->player.addr = mlx_get_data_addr(sprites->player.img,
				&sprites->player.bits_per_pixel, &sprites->player.line_length, \
				&sprites->player.endian);
}

void	check_img_settings(t_game *g, t_sprites *sprites, bool id_img)
{
	if (id_img)
	{
		if (!(sprites->door.addr))
			error_switchman(g, wrong_texture);
	}
	else
	{
		if (!(sprites->player.addr))
			error_switchman(g, wrong_texture);
	}
}
