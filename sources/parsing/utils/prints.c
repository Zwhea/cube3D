/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:11:24 by twang             #+#    #+#             */
/*   Updated: 2023/07/22 12:44:25 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	ft_error(t_game *g, bool is_err, bool is_warn, bool how_to, char *msg)
{
	is_this_first_mistake(g, is_err, is_warn);
	ft_dprintf(2, "%s", msg);
	if (how_to == true)
		usage();
}
