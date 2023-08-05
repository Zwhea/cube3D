/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_thea.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:02:27 by twang             #+#    #+#             */
/*   Updated: 2023/08/05 18:09:20 by twang            ###   ########.fr       */
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

/*---- authorized charset ----------------------------------------------------*/

# define TEXTURE_CHARSET "NOSOWEEA "
# define TEXTURE_NORTH "NO "
# define TEXTURE_SOUTH "SO "
# define TEXTURE_WEST "WE "
# define TEXTURE_EAST "EA "

# define COLOR_CHARSET "FC "
# define COLOR_FLOOR "F "
# define COLOR_CEILING "C "
# define COLOR_NM_CHARSET "0123456789, "

# define MAP_CHARSET "01NSEW "

/*---- sizes (windows, textures, images) -------------------------------------*/

# define WINDOW_X	1600
# define WINDOW_Y	1400
# define MINI_MAP_X	600
# define MINI_MAP_Y	400
# define LEGEND_X	600
# define LEGEND_Y	400

#endif