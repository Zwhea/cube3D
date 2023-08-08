/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_thea.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:02:27 by twang             #+#    #+#             */
/*   Updated: 2023/08/08 11:26:01 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_THEA_H
# define DEFINES_THEA_H

/*---- error messages --------------------------------------------------------*/

# define NO_ARG "\tprogram needs a map you fool !!!\n"
# define MUCH_ARG "program will only accept the first argument.\n"

# define WRONG_FILE "program encounter issues with given file\n"
# define WRONG_ASSET "program encounter issues with given informations\n"
# define WRONG_MAP "program encounter issues with given map\n"
# define WRONG_CHAR "you have an unwanted character in your map\n"
# define WRONG_PLAYER "you have an issue with player character in your map\n"

/*---- authorized charset ----------------------------------------------------*/

# define TEXTURE_CHARSET	"NOSOWEEA "
# define TEXTURE_NORTH		"NO "
# define TEXTURE_SOUTH		"SO "
# define TEXTURE_WEST		"WE "
# define TEXTURE_EAST		"EA "

# define COLOR_FLOOR		"F "
# define COLOR_CEILING		"C "
# define COLOR_CHARSET		"0123456789,"

# define MAP_CHARSET		"01NSEW \n"
# define PLAYER_CHARSET		"NSEW"

/*---- sizes (windows, textures, images) -------------------------------------*/

# define WINDOW_X			1600
# define WINDOW_Y			1400
# define MINI_MAP_X			600
# define MINI_MAP_Y			400
# define LEGEND_X			600
# define LEGEND_Y			400

/*---- colors ----------------------------------------------------------------*/

# define H_WHITE			0xffffff
# define H_BLACK			0x000000
# define H_RED				0xff0000
# define H_GREEN			0x00ff00
# define H_BLUE				0x0000ff
# define H_YELLOW			0xffff00
# define H_ORANGE			0xffa500
# define H_PINK				0xffc0cb
# define H_PURPLE			0x800080
# define H_GREY				0x808080

#endif