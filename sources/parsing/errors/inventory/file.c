/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:24:00 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/01 15:02:59 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	no_file(t_game *g)
{
	ft_error(g, false, true, NO_FILE);
}

void	failed_extract(t_game *g)
{
	ft_error(g, false, true, NO_EXTRACT);
}

