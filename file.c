/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:56:03 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/24 17:01:30 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	no_file(t_game *g)
{
	ft_error(g, true, false, true, NO_FILE);
}

/*
void	failed_extract(t_game *g)
{
	ft_error(g, true, false, true, NO_EXTRACT);
}
*/