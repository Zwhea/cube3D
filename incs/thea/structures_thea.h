/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_thea.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:07:42 by twang             #+#    #+#             */
/*   Updated: 2023/08/03 16:33:15 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_THEA_H
# define STRUCTURES_THEA_H

# include "enums_thea.h"

/*---- typedef structures ----------------------------------------------------*/

typedef struct s_lst_assets	t_lst_assets;
typedef struct s_sprite		t_sprite;
typedef struct s_map_error	t_map_error;
typedef struct s_tex		t_tex;
typedef struct s_color		t_color;
typedef struct s_vector		t_vector;
typedef struct s_map		t_map;
typedef struct s_file		t_file;
typedef struct s_game		t_game;

/*---- typedef function pointer ----------------------------------------------*/

typedef void				(*t_errors_ft)(t_game *g);
typedef void				(*t_assets_ft)(t_game *g, char *line);

/*---- structures ------------------------------------------------------------*/

struct s_lst_assets
{
	const char	*asset;
	t_assets_ft	func;
};

struct s_sprite
{
	void	*sprite;
};

struct s_map_error
{
	bool	is_valid;
};

struct s_color
{
	char	*col_floor;
	char	*col_ceiling;
};

struct s_tex
{
	t_sprite	walls[6];
};

struct s_vector
{
	int		x;
	int		y;
};

struct s_map
{
	t_map_error	error;
	t_vector	size;
	char		**map;
};

struct s_file
{
	int		fd;
	char	*file;
};

struct s_game
{
	t_file	file;
	t_map	map;
};

#endif