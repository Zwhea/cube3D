/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes_thea.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:25:03 by twang             #+#    #+#             */
/*   Updated: 2023/08/24 14:52:12 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_THEA_H
# define PROTOTYPES_THEA_H

/*---- includes --------------------------------------------------------------*/

# include "structures_thea.h"

/*----------------------------------------------------------------------------*/
/*---- clean/ ----------------------------------------------------------------*/
/*------------------------- clean_assets.c -----------------------------------*/

int		close_n_free(t_game *g, bool is_error);
void	clean_textures(t_game *g);
void	clean_maps(t_game *g);

/*------------------------- clean_windows.c ----------------------------------*/

int		clean_legend(t_game *g);
int		clean(t_game *g);

/*---- errors/ ---------------------------------------------------------------*/

void	error_switchman(t_game *g, t_keyerror error_key);
void	ft_error(bool how_to, char *msg);

/*--------------- inventory/ -------------------------------------------------*/
/*------------------------- argument.c ---------------------------------------*/

void	_no_arg(t_game *g);

/*------------------------- asset.c ------------------------------------------*/

void	_wrong_asset(t_game *g);
void	_wrong_texture(t_game *g);
void	_wrong_textures(t_game *g);
void	_wrong_color(t_game *g);
void	_wrong_colors(t_game *g);

/*------------------------- file.c -------------------------------------------*/

void	_wrong_file(t_game *g);

/*------------------------- map.c --------------------------------------------*/

void	_wrong_map(t_game *g);
void	_wrong_char(t_game *g);
void	_wrong_player(t_game *g);

/*---- init/ -----------------------------------------------------------------*/
/*--------------- legend/ ----------------------------------------------------*/
/*------------------------- init.c -------------------------------------------*/

int		legend_init(t_game *g);

/*--------------- mlx/ -------------------------------------------------------*/
/*------------------------- init.c -------------------------------------------*/

void	init_mlx(t_game *g);
void	init_mlx_functions(t_game *g);

/*--------------- struct/ ----------------------------------------------------*/
/*------------------------- init.c -------------------------------------------*/

void	init_struct(t_game *g);
void	set_vector(t_vector *vector, int x, int y);
void	set_vector_f(t_vector_f *vector, float x, float y);

/*---- motions/ --------------------------------------------------------------*/
/*------------------------- a_move.c -----------------------------------------*/

int		a_move(t_game *g);

/*------------------------- d_move.c -----------------------------------------*/

int		d_move(t_game *g);

/*------------------------- s_move.c -----------------------------------------*/

int		s_move(t_game *g);

/*------------------------- w_move.c -----------------------------------------*/

int		w_move(t_game *g);

/*---- parsing/ --------------------------------------------------------------*/

int		parsing(t_game *g, int ac, char **av);

/*--------------- assets/ ----------------------------------------------------*/

void	asset_switchman(t_game *g, char *line);

/*---------------------- colors/ ---------------------------------------------*/
/*------------------------- colors_checker.c ---------------------------------*/

void	colors_checker(t_game *g, char *line);
void	extract_colors(t_game *g, char *line, t_keyassets color_id);

/*------------------------- get_colors.c -------------------------------------*/

void	handle_ceiling_color(t_game *g, char *line);
void	handle_floor_color(t_game *g, char *line);
void	handle_no_asset(t_game *g, char *line);

/*------------------------- utils.c ------------------------------------------*/

void	extract_nbrs(t_game *g, t_keyassets color_id, int i, char *line);
int		create_rgb(int r, int g, int b);

/*---------------------- textures/ -------------------------------------------*/
/*------------------------- bonus_textures.c ---------------------------------*/

void	handle_ceiling_texture(t_game *g, char *line);
void	handle_floor_texture(t_game *g, char *line);

/*------------------------- get_textures.c -----------------------------------*/

void	handle_north_texture(t_game *g, char *line);
void	handle_south_texture(t_game *g, char *line);
void	handle_west_texture(t_game *g, char *line);
void	handle_east_texture(t_game *g, char *line);

/*------------------------- textures_checker.c -------------------------------*/

void	textures_checker(t_game *g);

/*--------------- map/ -------------------------------------------------------*/
/*------------------------- get_map.c ----------------------------------------*/

void	get_map(t_game *g, int fd, int start_map);

/*------------------------- map_checker.c ------------------------------------*/

void	map_checker(t_game *g);

/*------------------------- mini_map.c --------------------------------------*/

void	get_mini_map(t_game *g);

/*------------------------- utils.c ------------------------------------------*/

bool	is_map(char *s);
size_t	set_map_height(t_game *g, int fd);
void	set_map_width(t_game *g, char *line);
void	set_direction(t_game *g, char c);
void	check_around(t_game *g, int x, int y);

/*---- render/ ---------------------------------------------------------------*/
/*--------------- draw/ ------------------------------------------------------*/
/*------------------------- draw_line.c --------------------------------------*/

void	draw_line(t_game *g, t_vector start, t_vector end, int color);

/*------------------------- draw_square.c ------------------------------------*/

void	draw_square(t_game *g, int x, int y, int color);
void	draw_player_map_square(t_game *g, int x, int y, int color);

/*------------------------- fill_background.c --------------------------------*/

void	fill_background(t_game *g, int size_x, int size_y, int color);
void	draw_frame(t_game *g, int size_x, int size_y, int color);
void	init_map(t_game *g);

/*------------------------- mlx_pixel_put.c ----------------------------------*/

void	my_mlx_pixel_put(t_draw *draw, int x, int y, int color);

/*--------------- legend/ ----------------------------------------------------*/
/*------------------------- core.c -------------------------------------------*/

void	legend_render(t_game *g);

/*--------------- map/ -------------------------------------------------------*/
/*------------------------- core.c -------------------------------------------*/

void	map_render(t_game *g);

#endif