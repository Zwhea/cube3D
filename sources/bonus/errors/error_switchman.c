/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_switchman.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:06:00 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/11 16:09:36 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	error_switchman(t_game *g, t_keyerror error_key)
{
	const t_errors_ft	error_tab[] = {&_no_arg, &_wrong_file, \
								&_wrong_asset, &_wrong_texture, \
								&_wrong_textures, &_wrong_color, \
								&_wrong_colors, &_wrong_map, &_wrong_char, \
								&_wrong_player, &_trapped_player};

	(*error_tab[error_key])(g);
}

void	ft_error(bool how_to, char *msg)
{
	error();
	ft_dprintf(2, "%s", msg);
	if (how_to == true)
		usage();
}
