/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:19:50 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/01 12:10:57 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	parsing(t_game *g, int ac, char **av)
{
	if (ac > 2)
		error_switchman(g, too_much_args);
	if (!(get_file(g, av[1])))
		return (close_n_free(g, true));
	return (close_n_free(g, false));
}
