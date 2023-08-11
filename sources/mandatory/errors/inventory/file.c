/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:24:00 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/11 14:40:07 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	_wrong_file(t_game *g)
{
	if (g->file.fd)
		close(g->file.fd);
	ft_error(true, WRONG_FILE);
	clean(g);
}
