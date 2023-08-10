/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_switchman.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:06:00 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/08 11:32:18 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	error_switchman(t_game *g, t_keyerror error_key)
{
	const t_errors_ft	error_tab[] = {&_no_arg, &_much_arg, &_wrong_file, \
								&_wrong_asset, &_wrong_texture, &_wrong_color, \
								&_wrong_map, &_wrong_char, &_wrong_player};

	(*error_tab[error_key])(g);
}
