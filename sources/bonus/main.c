/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:46:37 by aascedu           #+#    #+#             */
/*   Updated: 2023/10/20 15:41:23 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_game	g;

	init_struct(&g);
	if (ac <= 1)
		error_switchman(&g, no_args);
	else
	{
		if (parsing(&g, av) != 0)
			return (close_file(g.file.fd));
		init_img(&g);
		game_display(&g);
		init_mlx_functions(&g);
		clean(&g);
	}
	return (0);
}
