/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_thea.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:07:42 by twang             #+#    #+#             */
/*   Updated: 2023/07/31 17:15:34 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_THEA_H
# define STRUCTURES_THEA_H

# include "enums_thea.h"

/*---- typedef structures ----------------------------------------------------*/

typedef struct s_map_error	t_map_error;
typedef struct s_sprite		t_sprite;
typedef struct s_tex		t_tex;
typedef struct s_color		t_color;
typedef struct s_map		t_map;
typedef struct s_file		t_file;
typedef struct s_game		t_game;

/*---- typedef function pointer ----------------------------------------------*/

typedef void				(*t_errors_ft)(t_game *g);

/*---- structures ------------------------------------------------------------*/

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
	char		*tex_north;
	char		*tex_south;
	char		*tex_west;
	char		*tex_east;
};

struct s_map
{
	t_map_error	error;
	int			size_y;
	char		**map;
};

struct s_file
{
	int		file_fd;
	int		size_file;
	char	*origin_file;
	char	**split_file;
};

struct s_game
{
	t_file	file;
	t_map	map;
};

#endif