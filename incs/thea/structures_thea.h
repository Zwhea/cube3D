/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_thea.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:07:42 by twang             #+#    #+#             */
/*   Updated: 2023/07/25 16:18:56 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_THEA_H
# define STRUCTURES_THEA_H

# include "enums_thea.h"

/*---- typedef structures ----------------------------------------------------*/

typedef struct s_map_error	t_map_error;
typedef struct s_sprite		t_sprite;
typedef struct s_textures	t_textures;
typedef struct s_map		t_map;
typedef struct s_game		t_game;

/*---- typedef function pointer ----------------------------------------------*/

typedef void				(*t_errors_ft)(t_game *g);

/*---- structures ------------------------------------------------------------*/

struct s_map_error
{
	bool	is_valid;
};

struct s_sprite
{
	void	*sprite;
};

struct s_textures
{
	t_sprite	walls_textures[4];
};

struct s_map
{
	t_map_error	error;
	char		**map;
};

struct s_game
{
	void	*mlx;
	void	*window;
	t_map	map;
};

#endif