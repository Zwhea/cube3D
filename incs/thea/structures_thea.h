/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_thea.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:07:42 by twang             #+#    #+#             */
/*   Updated: 2023/08/01 18:02:13 by wangthea         ###   ########.fr       */
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
typedef void				(*t_assets_ft)(t_game *g, char *line);

/*---- structures ------------------------------------------------------------*/

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
	/*toujours a 6, si on capte les textures sup, elles remplaceront les couleurs*/
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
};

struct s_game
{
	t_file	file;
	t_map	map;
};

#endif