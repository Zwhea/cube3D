/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:46:37 by aascedu           #+#    #+#             */
/*   Updated: 2023/08/23 08:46:38 by aascedu          ###   ########.fr       */
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
		if (parsing(&g, ac, av) != 0)
			return (close_n_free(&g, true));
		map_render(&g);
		init_mlx_functions(&g);
		clean(&g);
	}
	return (0);
}
<<<<<<< HEAD

/*
- revoir gestion d'erreurs

leaks, fds, mlx leaks, clean EVERYTHING YUP.
window opening no matter what

*/
=======
>>>>>>> c34d98654ae1c58689fc312bec068a1bd952bfab
