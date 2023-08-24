/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:38:50 by twang             #+#    #+#             */
/*   Updated: 2023/08/24 13:46:43 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_key_press(t_keycode key, t_game *g);

/*----------------------------------------------------------------------------*/

void	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		clean(g);
	set_vector(&g->window_size, WINDOW_X, WINDOW_Y);
	g->window = mlx_new_window(g->mlx, g->window_size.x, g->window_size.y, \
									"Cub3D");
	if (g->window == NULL)
		clean(g);
}

void	init_mlx_functions(t_game *g)
{
	mlx_key_hook(g->window, _key_press, g);
	mlx_hook(g->window, 17, 1L << 17, clean, g);
	mlx_loop(g->mlx);
}

static int	_key_press(t_keycode key, t_game *g)
{
	int					i;
	const t_lst_react	react_tab[] = {{esc_key, &clean}, \
										{l_key, &legend_init}, \
										{w_key, &w_move}, \
										{a_key, &a_move}, \
										{s_key, &s_move}, \
										{d_key, &d_move}};

	i = -1;
	while (++i < 6)
	{
		if (key == react_tab[i].key)
			return (react_tab[i].func(g));
	}
	return (0);
}
