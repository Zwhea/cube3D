/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:07:42 by twang             #+#    #+#             */
/*   Updated: 2023/10/23 09:41:29 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "enums.h"

/*---- typedef structures ----------------------------------------------------*/

typedef struct s_game		t_game;
typedef struct s_raycast	t_raycast;
typedef struct s_doorcast	t_doorcast;
typedef struct s_file		t_file;
typedef struct s_map		t_map;
typedef struct s_minimap	t_minimap;
typedef struct s_player		t_player;
typedef struct s_door		t_door;
typedef struct s_sprites	t_sprites;
typedef struct s_tex		t_tex;
typedef struct s_color		t_color;
typedef struct s_lst_assets	t_lst_assets;
typedef struct s_lst_react	t_lst_react;
typedef struct s_lst_moves	t_lst_moves;
typedef struct s_vector		t_vector;
typedef struct s_vector_f	t_vector_f;
typedef struct s_draw		t_draw;
typedef struct s_switches	t_switches;

/*---- typedef function pointer ----------------------------------------------*/

typedef void				(*t_errors_ft)(t_game *g);
typedef void				(*t_assets_ft)(t_game *g, char *line);
typedef int					(*t_keys_ft)(t_game *g);
typedef int					(*t_moves_ft)(t_game *g);

/*---- structures ------------------------------------------------------------*/

struct s_switches
{
	bool			mouse;
	bool			w_key;
	bool			a_key;
	bool			s_key;
	bool			d_key;
	bool			up_key;
	bool			down_key;
	bool			left_key;
	bool			right_key;
	bool			l_key;
	bool			space_key;
	bool			h_henri;
};

struct s_draw
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
};

struct s_vector
{
	int				x;
	int				y;
};

struct s_vector_f
{
	double			x;
	double			y;
};

struct s_lst_assets
{
	const char		*asset;
	t_assets_ft		func;
};

struct s_lst_react
{
	t_keycode		key;
	t_keys_ft		func;
};

struct s_lst_moves
{
	bool			switcher;
	t_moves_ft		func;
};

struct s_color
{
	u_int32_t		color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	bool			get;
};

struct s_sprites
{
	t_draw			player;
	t_draw			door;
	int				nb_of_doors;
	bool			animation;
};

struct s_tex
{
	t_draw			walls[4];
	t_vector_f		impact;
	double			h_ratio;
	double			l_ratio;
};

struct s_player
{
	t_vector		pos;
	t_vector_f		posf;
	t_vector_f		start;
	t_vector_f		view;
	double			angle_view;
	int				player;
	int				last_pov;
	int				diff_pov;
	bool			north;
	bool			south;
	bool			west;
	bool			east;
	double			hand_move;
};

struct s_door
{
	t_vector		pos;
	float			move;
	t_door_stat		status;
};

struct s_map
{
	t_vector		size;
	int				*line_len;
	char			**map;
	char			**b_map;
	char			**mini_map;
};

struct s_minimap
{
	int				center;
	int				rayon;
	float			ratio;
	float			monitor_start;
	float			indic_start;
	t_vector_f		indic;
	t_vector_f		monitor;
	float			plane_y;
	float			throw_x;
	float			throw_y;
	float			degree;
	int				fader;
	unsigned int	color;
	t_vector		north;
};

struct s_file
{
	int				fd;
	char			*file;
};

struct s_raycast
{
	t_vector_f		ray_start;
	t_vector_f		ray_dir;
	t_vector_f		ray_unit;
	t_vector_f		ray_len;
	t_vector_f		f;
	t_vector		check;
	t_vector		step;
	int				wall;
	int				door;
	int				side;
	double			dist;
	t_vector_f		intersection;
	double			cam_dist;
	double			wall_ratio;
	double			wall_size;
	int				top_wall;
	int				bottom_wall;
	int				wall_dir;
};

struct s_doorcast
{
	t_vector_f		ray_start;
	t_vector_f		ray_dir;
	t_vector_f		ray_unit;
	t_vector_f		ray_len;
	t_vector		check;
	t_vector		step;
	int				wall;
	int				door;
	double			dist;
	t_vector_f		intersection;
	double			cam_dist;
	double			wall_ratio;
	double			wall_size;
	int				top_wall;
	int				bottom_wall;
	int				wall_dir;
};

struct s_game
{
	t_file			file;
	t_map			map;
	t_minimap		mini_map;
	t_player		player;
	t_door			*doors;
	t_vector		size;
	t_vector		window_size;
	t_sprites		sprites;
	t_tex			textures;
	t_color			color[2];
	t_draw			draw;
	t_draw			legend;
	t_switches		switches;
	t_raycast		ray;
	t_doorcast		door;
	int				id;
	int				henri;
	void			*mlx;
	void			*window;
};

#endif