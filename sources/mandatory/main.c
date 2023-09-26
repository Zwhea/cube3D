/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:46:37 by aascedu           #+#    #+#             */
/*   Updated: 2023/09/26 13:40:14 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

int	main(int ac, char **av)
{
	t_game	g;

	init_struct(&g);
	if (ac <= 1)
		error_switchman(&g, no_args);
	else
	{
		if (parsing(&g, av) != 0)
			return (close_n_free(&g, true));
		game_display(&g);
		init_mlx_functions(&g);
		clean(&g);
	}
	return (0);
}
