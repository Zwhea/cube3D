#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_key_press(t_keycode key, t_game *g);

static void	_mini_map_render(t_game *g);
static void	_draw_square(t_game *g, int x, int y, int color);
static void	my_mlx_pixel_put(t_draw *draw, int x, int y, int color);

/*----------------------------------------------------------------------------*/

int	main(int ac, char **av)
{
	t_game	g;

	init_struct(&g);
	if (ac <= 1)
		error_switchman(&g, no_args);
	else
	{
		init_mlx(&g);
		if (parsing(&g, ac, av))
			return (close_n_free(&g, true));
		_mini_map_render(&g);
		mlx_key_hook(g.window, _key_press, &g);
		mlx_hook(g.window, 17, 1L << 17, clean, &g);
		mlx_loop(g.mlx);
		clean(&g);
	}
	return (0);
}

static int	_key_press(t_keycode key, t_game *g)
{
	if (key == esc_key)
		clean(g);
	return (0);
}

static void	_mini_map_render(t_game *g)
{
	t_vector	start;
	t_vector	end;

	start.x = 0;
	start.y = 0;
	end.x = MINI_MAP_Y;
	end.y = MINI_MAP_X;
	g->draw.img = mlx_new_image(g->mlx, WINDOW_X, WINDOW_Y);
	g->draw.addr = mlx_get_data_addr(g->draw.img, &g->draw.bits_per_pixel, \
										&g->draw.line_length, &g->draw.endian);
	_draw_square(g, 50, 50, g->colors.rgb[1].color);
	mlx_put_image_to_window(g->mlx, g->window, g->draw.img, 0, 0);
	mlx_destroy_image(g->mlx, g->draw.img);
}

static void	my_mlx_pixel_put(t_draw *draw, int x, int y, int color)
{
	char	*dst;

	dst = draw->addr + (y * draw->line_length + x * (draw->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	_draw_square(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			my_mlx_pixel_put(&g->draw, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

/*

mlx

- afficher une texture sur la window
- define texture && window size
- creer deux autres windows pour la mini map + legende
- close les windows avec mlx loop hook - croix rouge + echap

parsing + mlx

- get colors

parsing

- parsing map
- backtracking de ses morts

parsing

- revoir gestion d'erreurs

leaks, fds, mlx leaks, clean EVERYTHING YUP.

*/