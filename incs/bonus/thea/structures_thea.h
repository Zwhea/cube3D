/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_thea.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:07:42 by twang             #+#    #+#             */
/*   Updated: 2023/08/06 16:44:49 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_THEA_H
# define STRUCTURES_THEA_H

# include "enums_thea.h"

/*---- typedef structures ----------------------------------------------------*/

typedef struct s_game		t_game;
typedef struct s_file		t_file;
typedef struct s_map		t_map;
typedef struct s_tex		t_tex;
typedef struct s_sprite		t_sprite;
typedef struct s_lst_assets	t_lst_assets;
typedef struct s_vector		t_vector;
typedef struct s_draw		t_draw;

/*---- typedef function pointer ----------------------------------------------*/

typedef void				(*t_errors_ft)(t_game *g);
typedef void				(*t_assets_ft)(t_game *g, char *line);

/*---- structures ------------------------------------------------------------*/

struct s_draw
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_vector
{
	int		x;
	int		y;
};

struct s_lst_assets
{
	const char	*asset;
	t_assets_ft	func;
};

struct s_sprite
{
	void	*sprite;
};

struct s_tex
{
	t_sprite	walls[6];
	t_vector	size;
};

struct s_map
{
	t_vector	size;
	char		**map;
	bool		error;
};

struct s_file
{
	int		fd;
	char	*file;
};

struct s_game
{
	t_draw		draw;
	t_file		file;
	t_map		map;
	t_vector	window_size;
	t_vector	map_window_size;
	t_vector	legend_window_size;
	t_tex		textures;
	void		*mlx;
	void		*window;
	void		*map_window;
	void		*legend_window;
};

#endif