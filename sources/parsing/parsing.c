/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:19:50 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/02 19:13:19 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	parsing(t_game *g, int ac, char **av)
{
	if (ac > 2)
		error_switchman(g, much_args);
	if (check_file(g, av[1]))
	{
		
	}
	else
		return(error_switchman(g, wrong_file));
	return (0);
}








/*
int	parsing(t_game *g, int ac, char **av)
{
	if (ac > 2)
		error_switchman(g, too_much_args);
	if (!(get_file(g, av[1])))
		return (close_n_free(g, true));
	return (close_n_free(g, false));
}
*/