# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twang <twang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 14:25:51 by twang             #+#    #+#              #
#    Updated: 2023/10/23 09:47:29 by twang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES_BONUS =																\
					sources/bonus/clean/clean_assets.c						\
					sources/bonus/clean/clean_windows.c						\
					sources/bonus/displays/animations/doors.c				\
					sources/bonus/displays/animations/player.c				\
					sources/bonus/displays/draw/draw_ceiling_n_floor.c		\
					sources/bonus/displays/draw/draw_circle.c				\
					sources/bonus/displays/draw/draw_crosshair.c			\
					sources/bonus/displays/draw/mlx_pixel_get.c				\
					sources/bonus/displays/draw/mlx_pixel_put.c				\
					sources/bonus/displays/game/raycasting/ray_door.c		\
					sources/bonus/displays/game/raycasting/raycasting.c		\
					sources/bonus/displays/game/raycasting/utils.c			\
					sources/bonus/displays/game/texturing/texturing.c		\
					sources/bonus/displays/game/texturing/utils.c			\
					sources/bonus/displays/game/core.c						\
					sources/bonus/displays/game/easter_egg.c				\
					sources/bonus/displays/mini_map/raycasting/ray_minimap.c\
					sources/bonus/displays/mini_map/utils/utils.c			\
					sources/bonus/displays/mini_map/core.c					\
					sources/bonus/displays/motions/check_if_movable.c		\
					sources/bonus/displays/motions/doors.c					\
					sources/bonus/displays/motions/motions.c				\
					sources/bonus/displays/viewing_range/viewing_range.c	\
					sources/bonus/errors/inventory/argument.c				\
					sources/bonus/errors/inventory/asset.c					\
					sources/bonus/errors/inventory/file.c					\
					sources/bonus/errors/inventory/map.c					\
					sources/bonus/errors/error_switchman.c					\
					sources/bonus/init/mlx/init.c							\
					sources/bonus/init/struct/init.c						\
					sources/bonus/init/switches/key_switchman.c				\
					sources/bonus/init/switches/mouse_switchman.c			\
					sources/bonus/parsing/assets/animations/init_textures.c	\
					sources/bonus/parsing/assets/animations/utils.c			\
					sources/bonus/parsing/assets/colors/get_colors.c		\
					sources/bonus/parsing/assets/colors/utils.c				\
					sources/bonus/parsing/assets/doors/set_doors.c			\
					sources/bonus/parsing/assets/textures/get_textures.c	\
					sources/bonus/parsing/assets/asset_checker.c			\
					sources/bonus/parsing/assets/asset_switchman.c			\
					sources/bonus/parsing/map/get_map.c						\
					sources/bonus/parsing/map/map_checker.c					\
					sources/bonus/parsing/map/utils.c						\
					sources/bonus/parsing/parsing.c							\
					sources/bonus/main.c