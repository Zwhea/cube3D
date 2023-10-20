/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_switchman.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:06:00 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/20 13:55:44 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_switchman(t_game *g, t_keyerror error_key)
{
	const t_errors_ft	error_tab[] = {&_no_arg, &_wrong_file, \
								&_wrong_asset, &_wrong_texture, \
								&_wrong_textures, &_wrong_color, \
								&_wrong_colors, &_wrong_map, &_wrong_char, \
								&_wrong_player, &_wrong_door};

	(*error_tab[error_key])(g);
}

void	ft_error(bool how_to, char *msg)
{
	error();
	ft_dprintf(2, "%s", msg);
	if (how_to == true)
		usage();
}
