# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_thea.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twang <twang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 14:25:51 by twang             #+#    #+#              #
#    Updated: 2023/09/04 09:42:51 by twang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES_BONUS +=															\
					sources/bonus/clean/clean_assets.c						\
					sources/bonus/clean/clean_windows.c						\
					sources/bonus/errors/inventory/argument.c				\
					sources/bonus/errors/inventory/asset.c					\
					sources/bonus/errors/inventory/file.c					\
					sources/bonus/errors/inventory/map.c					\
					sources/bonus/errors/error_switchman.c					\
					sources/bonus/init/legend/init.c						\
					sources/bonus/init/mlx/init.c							\
					sources/bonus/init/mlx/key_switchman.c					\
					sources/bonus/init/struct/init.c						\
					sources/bonus/motions/a_move.c							\
					sources/bonus/motions/d_move.c							\
					sources/bonus/motions/doors.c							\
					sources/bonus/motions/s_move.c							\
					sources/bonus/motions/w_move.c							\
					sources/bonus/parsing/assets/colors/colors_checker.c	\
					sources/bonus/parsing/assets/colors/get_colors.c		\
					sources/bonus/parsing/assets/colors/utils.c				\
					sources/bonus/parsing/assets/textures/bonus_textures.c	\
					sources/bonus/parsing/assets/textures/get_textures.c	\
					sources/bonus/parsing/assets/textures/textures_checker.c\
					sources/bonus/parsing/assets/asset_switchman.c			\
					sources/bonus/parsing/map/get_map.c						\
					sources/bonus/parsing/map/map_checker.c					\
					sources/bonus/parsing/map/mini_map.c					\
					sources/bonus/parsing/map/utils.c						\
					sources/bonus/parsing/parsing.c							\
					sources/bonus/render/draw/draw_line.c					\
					sources/bonus/render/draw/fill_background.c				\
					sources/bonus/render/draw/mlx_pixel_put.c				\
					sources/bonus/render/legend/core.c						\
					sources/bonus/render/map/core.c							\
					sources/bonus/render/map/utils.c						\
					sources/bonus/viewing_range/view_left.c					\
					sources/bonus/viewing_range/view_right.c				\
					sources/bonus/main.c