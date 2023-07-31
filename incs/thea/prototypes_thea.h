/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes_thea.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:25:03 by twang             #+#    #+#             */
/*   Updated: 2023/07/31 13:10:39 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_THEA_H
# define PROTOTYPES_THEA_H

/*---- includes --------------------------------------------------------------*/

# include "structures_thea.h"

/*----------------------------------------------------------------------------*/

/*---- parsing ---------------------------------------------------------------*/

int		parsing(t_game *g, int ac, char **av);

/*--------------- assets -----------------------------------------------------*/
/*------------------------- check_assets.c -----------------------------------*/

int		check_textures(t_game *g);
int		check_colors(t_game *g);

/*------------------------- get_assets.c -------------------------------------*/

int		get_assets(t_game *g);

/*--------------- errors -----------------------------------------------------*/
/*---------------------- inventory -------------------------------------------*/
/*------------------------- argument.c ---------------------------------------*/

void	no_arg(t_game *g);
void	too_much_arg(t_game *g);

/*------------------------- asset.c ------------------------------------------*/

/*------------------------- file.c -------------------------------------------*/

void	no_file(t_game *g);
void	failed_extract(t_game *g);

/*------------------------- map.c --------------------------------------------*/

/*------------------------- error_switchman.c --------------------------------*/

void	error_switchman(t_game *g, t_error_keys error_key);

/*--------------- file -------------------------------------------------------*/
/*------------------------- get_file.c ---------------------------------------*/

char	**get_file(t_game *g, char *file);

/*------------------------- utils.c ------------------------------------------*/

void	read_error(int fd);
int		get_alloc_size(const char *file);
int		is_north_texture(int start, char *s);
int		is_south_texture(int start, char *s);
int		is_west_texture(int start, char *s);
int		is_east_texture(int start, char *s);

/*--------------- map --------------------------------------------------------*/
/*------------------------- get_map.c ----------------------------------------*/

int		check_file(char *file);

/*------------------------- get_map.c ----------------------------------------*/
int		get_map(t_game *g, char *file);

/*--------------- utils ------------------------------------------------------*/
/*------------------------- checkers.c ---------------------------------------*/

void	is_this_first_mistake(t_game *g, bool is_warning);

/*------------------------- clean.c ---------------------------------------*/

int		close_n_free(t_game *g, bool is_error);

/*------------------------- prints.c -----------------------------------------*/

void	ft_error(t_game *g, bool is_warn, bool how_to, char *msg);
#endif