/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:38:50 by twang             #+#    #+#             */
/*   Updated: 2023/09/04 08:05:41 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_key_click(t_keycode key, t_game *g);
static int	_key_press(t_keycode key, t_game *g);
static int	_mouse_move(int x, int y, t_game *g);
static int	open_door(t_game *g);

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
	mlx_mouse_hook(g->window, _key_click, g);
	mlx_hook(g->window, 2, 1L << 0, _key_press, g);
	mlx_hook(g->window, 6, 1L << 6, _mouse_move, g);
	mlx_hook(g->window, 17, 1L << 17, clean, g);
	mlx_loop(g->mlx);
}

static int	_mouse_move(int x, int y, t_game *g)
{
	(void)y;
	if (g->player.last_pov > x + 0.5)
	{
		g->player.diff_pov = (g->player.last_pov - x) / 5;
		view_left(g);
	}
	if (g->player.last_pov < x - 0.5)
	{
		g->player.diff_pov = (x - g->player.last_pov) / 5;
		view_right(g);
	}
	g->player.last_pov = x;
	return (0);
}

static int	_key_press(t_keycode key, t_game *g)
{
	int					i;
	const t_lst_react	react_tab[] = {{esc_key, &clean}, \
										{l_key, &legend_init}, \
										{w_key, &w_move}, \
										{a_key, &a_move}, \
										{s_key, &s_move}, \
										{d_key, &d_move}, \
										{up_key, &w_move}, \
										{down_key, &s_move}, \
										{left_key, &view_left}, \
										{right_key, &view_right}};

	i = -1;
	if (g->player.diff_pov != 1 && g->player.last_pov > 0)
		g->player.diff_pov = 1;
	while (++i < 11)
	{
		if (key == react_tab[i].key)
			return (react_tab[i].func(g));
	}
	return (0);
}

static int	_key_click(t_keycode key, t_game *g)
{
	int					i;
	const t_lst_react	reacti_tab[] = {{m_left_key, &open_door}};

	i = -1;
	while (++i < 1)
	{
		if (key == reacti_tab[i].key)
			return (reacti_tab[i].func(g));
	}
	return (0);
}

static int	open_door(t_game *g)
{
	(void)g;
	puts("ouvrir porte");
	puts("si ouvert, fermer porte");
	return (0);
}