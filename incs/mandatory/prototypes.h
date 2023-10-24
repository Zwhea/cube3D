/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:12:57 by aascedu           #+#    #+#             */
/*   Updated: 2023/10/20 13:25:12 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/*---- includes --------------------------------------------------------------*/

# include "structures.h"

/*---- prototypes ------------------------------------------------------------*/

/*---- clean/ ----------------------------------------------------------------*/
/*------------------------- clean_assets.c -----------------------------------*/
void			clean_textures(t_game *g);
void			clean_maps(t_game *g);
/*------------------------- clean_windows.c ----------------------------------*/
int				clean(t_game *g);

/*---- displays/ -------------------------------------------------------------*/
/*--------------- draw/ ------------------------------------------------------*/
/*------------------------- draw_ceiling_n_floor.c ---------------------------*/
void			draw_ceiling_n_floor(t_game *g, int size_x, int size_y, \
																	int color);
/*------------------------- draw_crosshair.c ---------------------------------*/
void			draw_crosshair(t_game *g);
/*------------------------- mlx_pixel_put.c ----------------------------------*/
void			my_mlx_pixel_put(t_draw *data, int x, int y, int color);
/*------------------------- mlx_pixel_get.c ----------------------------------*/
unsigned int	my_mlx_pix_get(t_draw *draw, int x, int y);
/*--------------- game/ ------------------------------------------------------*/
/*---------------------- raycasting/ -----------------------------------------*/
/*------------------------- raycasting.c -------------------------------------*/
void			raycasting(t_game *g, double angle);
/*---------------------- texturing/ ------------------------------------------*/
/*------------------------- texturing.c --------------------------------------*/
void			find_dir_wall(t_game *g, int check);
void			draw_textures(t_game *g);
/*--------------- core.c -----------------------------------------------------*/
void			game_display(t_game *g);

/*--------------- motions/ ---------------------------------------------------*/
/*------------------------- check_if_movable.c -------------------------------*/
int				check_x(t_game *g, int next_x);
int				check_y(t_game *g, int next_y);
/*------------------------- motions.c ----------------------------------------*/
int				w_move(t_game *g);
int				a_move(t_game *g);
int				s_move(t_game *g);
int				d_move(t_game *g);
/*--------------- viewing_range/ ---------------------------------------------*/
/*------------------------- viewing_range.c ----------------------------------*/
int				view_left(t_game *g);
int				view_right(t_game *g);

/*---- errors/ ---------------------------------------------------------------*/
/*--------------- inventory/ -------------------------------------------------*/
/*------------------------- argument.c ---------------------------------------*/
void			_no_arg(t_game *g);
/*------------------------- asset.c ------------------------------------------*/
void			_wrong_asset(t_game *g);
void			_wrong_texture(t_game *g);
void			_wrong_textures(t_game *g);
void			_wrong_color(t_game *g);
void			_wrong_colors(t_game *g);
/*------------------------- file.c -------------------------------------------*/
void			_wrong_file(t_game *g);
/*------------------------- map.c --------------------------------------------*/
void			_wrong_map(t_game *g);
void			_wrong_char(t_game *g);
void			_wrong_player(t_game *g);
/*---- error_switchman.c -----------------------------------------------------*/
void			error_switchman(t_game *g, t_keyerror error_key);
void			ft_error(bool how_to, char *msg);

/*---- init/ -----------------------------------------------------------------*/
/*--------------- mlx/ -------------------------------------------------------*/
/*------------------------- init.c -------------------------------------------*/
void			init_mlx(t_game *g);
void			init_img(t_game *g);
void			init_mlx_functions(t_game *g);
/*--------------- struct/ ----------------------------------------------------*/
/*------------------------- init.c -------------------------------------------*/
void			init_struct(t_game *g);
void			set_vector(t_vector *vector, int x, int y);
void			set_vector_f(t_vector_f *vector, float x, float y);
/*--------------- switches/ --------------------------------------------------*/
/*------------------------- key_switchman.c ----------------------------------*/
int				key_manager(t_game *g);
int				key_switch(t_keycode key, t_game *g);
int				key_release(t_keycode key, t_game *g);

/*---- parsing/ --------------------------------------------------------------*/
/*--------------- assets/ ----------------------------------------------------*/
/*---------------------- colors/ ---------------------------------------------*/
/*------------------------- get_colors.c -------------------------------------*/
void			handle_ceiling_color(t_game *g, char *line);
void			handle_floor_color(t_game *g, char *line);
void			handle_no_asset(t_game *g, char *line);
int				colors_checker(t_game *g, char *line);
/*------------------------- utils.c ------------------------------------------*/
void			extract_colors(t_game *g, char *line, t_keyassets color_id, \
				char *str);
int				extrct_nbrs(t_game *g, t_keyassets color_id, int i, char *line);
int				create_rgb(int r, int g, int b);
/*---------------------- textures/ -------------------------------------------*/
/*------------------------- get_textures.c -----------------------------------*/
void			handle_north_texture(t_game *g, char *line);
void			handle_south_texture(t_game *g, char *line);
void			handle_west_texture(t_game *g, char *line);
void			handle_east_texture(t_game *g, char *line);
int				init_textures(t_game *g, char *s, int id);
/*--------------- asset_checker.c --------------------------------------------*/
void			textures_checker(t_game *g);
void			color_checker(t_game *g);
/*--------------- asset_switchman.c ------------------------------------------*/
void			asset_switchman(t_game *g, char *line);
/*--------------- map/ -------------------------------------------------------*/
/*------------------------- get_map.c ----------------------------------------*/
void			get_map(t_game *g, int fd, int start_map);
/*------------------------- map_checker.c ------------------------------------*/
float			get_angle_degree(t_game *g);
void			map_checker(t_game *g);
/*------------------------- utils.c ------------------------------------------*/
bool			is_map(char *s);
size_t			set_map_height(t_game *g, int fd);
void			set_map_width(t_game *g, char *line);
void			set_direction(t_game *g, char c);
void			check_around(t_game *g, int x, int y);
/*---- parsing.c -------------------------------------------------------------*/
int				parsing(t_game *g, char **av);

#endif
