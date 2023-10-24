/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:25:03 by twang             #+#    #+#             */
/*   Updated: 2023/10/23 13:13:40 by twang            ###   ########.fr       */
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
/*--------------- animations/ ------------------------------------------------*/
/*------------------------- doors.c ------------------------------------------*/
int				get_id(t_game *g, int x, int y);
void			door_animations(t_game *g);
/*------------------------- player.c -----------------------------------------*/
void			player_animation(t_game *g);
/*--------------- draw/ ------------------------------------------------------*/
/*------------------------- draw_ceiling_n_floor.c ---------------------------*/
void			draw_ceiling_n_floor(t_game *g, int size_x, int size_y, \
																	int color);
/*------------------------- draw_circle.c ------------------------------------*/
void			draw_circle(t_game *g, t_vector *pos, int rayon, int color);
/*------------------------- draw_crosshair.c ---------------------------------*/
void			draw_crosshair(t_game *g);
/*------------------------- mlx_pixel_get.c ----------------------------------*/
unsigned int	my_mlx_pix_get(t_draw *draw, int x, int y);
/*------------------------- mlx_pixel_put.c ----------------------------------*/
void			my_mlx_pixel_put(t_draw *data, int x, int y, int color);
/*--------------- game/ ------------------------------------------------------*/
/*---------------------- raycasting/ -----------------------------------------*/
/*------------------------- ray_door.c ---------------------------------------*/
int				dstate(t_game *g, int x, int y, float angle);
int				depth_door(t_game *g, float dx, double angle);
/*------------------------- raycasting.c -------------------------------------*/
void			raycasting(t_game *g, double angle);
/*------------------------- utils.c ------------------------------------------*/
int				get_south(t_game *g, int id, double inter, double angle);
int				get_north(t_game *g, int id, double inter, double angle);
int				get_west(t_game *g, int id, double inter, double angle);
int				get_east(t_game *g, int id, double inter, double angle);
/*---------------------- texturing/ ------------------------------------------*/
/*------------------------- utils.c ------------------------------------------*/
void			find_dir_wall(t_game *g, int check);
unsigned int	get_door_color(t_game *g, t_vector texture, double wall_x);
/*------------------------- texturing.c --------------------------------------*/
void			draw_textures(t_game *g);
/*------------------------- utils.c ------------------------------------------*/
void			find_dir_wall(t_game *g, int check);
unsigned int	get_shade(t_game *game, unsigned int color);
/*--------------- core.c -----------------------------------------------------*/
void			game_display(t_game *g);
/*--------------- easter_egg.c -----------------------------------------------*/
void			thx_henri(t_game *g);
void			switch_henri(t_game *g);
/*--------------- mini_map/ --------------------------------------------------*/
/*---------------------- raycasting/ -----------------------------------------*/
/*------------------------- ray_minimap.c ------------------------------------*/
float			get_angle_degree(t_game *g);
void			ray_minimap(t_game *g, t_minimap *mini);
/*---------------------- utils/ ----------------------------------------------*/
/*------------------------- utils.c ------------------------------------------*/
int				door_direction(t_game *g, int x, int y);
void			draw_north(t_game *g);
/*--------------- core.c -----------------------------------------------------*/
void			minimap_display(t_game *g);
/*--------------- motions/ ---------------------------------------------------*/
/*------------------------- check_if_movable.c -------------------------------*/
int				check_x(t_game *g, int next_x);
int				check_y(t_game *g, int next_y);
/*------------------------- doors.c ------------------------------------------*/
int				open_door(t_game *g);
int				ray_door(t_game *g);
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
void			_wrong_door(t_game *g);
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
/*------------------------- mouse_switchman.c --------------------------------*/
int				mouse_switch(t_keycode key, int x, int y, t_game *g);
int				mouse_move(int x, int y, t_game *g);
int				mouse_release(t_keycode key, int x, int y, t_game *g);

/*---- parsing/ --------------------------------------------------------------*/
/*--------------- assets/ ----------------------------------------------------*/
/*---------------------- animations/ -----------------------------------------*/
/*------------------------- init_textures.c ----------------------------------*/
void			init_door_sprites(t_game *g);
void			init_player_sprites(t_game *g);
/*------------------------- utils.c ------------------------------------------*/
void			init_image(t_game *g, t_sprites *sprites, bool id_img);
void			init_img_settings(t_sprites *sprites, bool id_img);
void			check_img(t_game *g, t_sprites *sprites, bool id_img);
void			check_img_settings(t_game *g, t_sprites *sprites, bool id_img);
/*---------------------- colors/ ---------------------------------------------*/
/*------------------------- colors_checker.c ---------------------------------*/
int				colors_checker(t_game *g, char *line);
void			extract_colors(t_game *g, char *line, t_keyassets color_id, \
				char *str);
/*------------------------- get_colors.c -------------------------------------*/
void			handle_ceiling_color(t_game *g, char *line);
void			handle_floor_color(t_game *g, char *line);
void			handle_no_asset(t_game *g, char *line);
/*------------------------- utils.c ------------------------------------------*/
int				extrct_nbrs(t_game *g, t_keyassets color_id, int i, char *line);
int				create_rgb(int r, int g, int b);
/*---------------------- doors/ ----------------------------------------------*/
/*------------------------- set_door.c ---------------------------------------*/
void			set_doors(t_game *g);
/*---------------------- textures/ -------------------------------------------*/
/*------------------------- get_textures.c -----------------------------------*/
void			handle_north_texture(t_game *g, char *line);
void			handle_south_texture(t_game *g, char *line);
void			handle_west_texture(t_game *g, char *line);
void			handle_east_texture(t_game *g, char *line);
int				init_textures(t_game *g, char *s, int id);
/*------------------------- get_textures.c -----------------------------------*/
void			textures_checker(t_game *g);
void			color_checker(t_game *g);

/*--------------- asset_switchman.c ------------------------------------------*/
void			asset_switchman(t_game *g, char *line);
/*--------------- map/ -------------------------------------------------------*/
/*------------------------- get_map.c ----------------------------------------*/
void			get_map(t_game *g, int fd, int start_map);
void			get_mini_map(t_game *g);
/*------------------------- map_checker.c ------------------------------------*/
void			map_checker(t_game *g);
void			minimap_display(t_game *g);
/*------------------------- utils.c ------------------------------------------*/
bool			is_map(char *s);
size_t			set_map_height(t_game *g, int fd);
void			set_map_width(t_game *g, char *line);
void			set_direction(t_game *g, char c);
void			check_around(t_game *g, int x, int y);
/*---- parsing.c -------------------------------------------------------------*/
int				parsing(t_game *g, char **av);

#endif