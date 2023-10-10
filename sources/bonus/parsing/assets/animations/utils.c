/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:17:51 by twang             #+#    #+#             */
/*   Updated: 2023/10/10 11:27:27 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	init_image(t_game *g, t_sprites *sprites, int size, bool id_img)
{
	int			i;
	const char	*door_path[3] = {XPM_DOOR_00, XPM_DOOR_01, XPM_DOOR_02};
	const char	*player_path[3] = {XPM_PLAYER_00, XPM_PLAYER_01, XPM_PLAYER_02};

	i = -1;
	while (++i < size)
	{
		if (id_img)
			sprites->door[i].img = mlx_xpm_file_to_image(g->mlx, \
											(char *)door_path[i], \
											&sprites->door[i].width, \
											&sprites->door[i].height);
		else
			sprites->player[i].img = mlx_xpm_file_to_image(g->mlx, \
											(char *)player_path[i], \
											&sprites->player[i].width, \
											&sprites->player[i].height);
	}
}

void	init_image_settings(t_sprites *sprites, int size, bool id_img)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (id_img)
			sprites->door[i].addr = mlx_get_data_addr(sprites->door[i].img, \
					&sprites->door[i].bits_per_pixel, \
					&sprites->door[i].line_length, \
					&sprites->door[i].endian);
		else
			sprites->player[i].addr = mlx_get_data_addr(sprites->player[i].img,
					&sprites->player[i].bits_per_pixel, \
					&sprites->player[i].line_length, \
					&sprites->player[i].endian);
	}
}

void	check_image(t_game *g, t_sprites *sprites, int size, bool id_img)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (id_img)
		{
			if (!(sprites->door[i].img))
				error_switchman(g, wrong_texture);
		}
		else
		{
			if (!(sprites->player[i].img))
				error_switchman(g, wrong_texture);
		}
	}
}

void	check_image_settings(t_game *g, t_sprites *sprites, int size, bool id)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (id)
		{
			if (!(sprites->door[i].addr))
				error_switchman(g, wrong_texture);
		}
		else
		{
			if (!(sprites->player[i].addr))
				error_switchman(g, wrong_texture);
		}
	}
}
