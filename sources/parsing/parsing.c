/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:19:50 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/27 17:59:30 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	parsing(t_game *g, int ac, char **av)
{
	char	*file;
	
	if (ac > 2)
		error_switchman(g, too_much_args);
	file = get_file(g, av[1]);
	if (!(file))
		return (-1);
	if (get_assets(g, file) == -1)
		return (-1);
	return (0);
}
