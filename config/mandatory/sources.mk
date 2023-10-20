# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twang <twang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 14:25:51 by twang             #+#    #+#              #
#    Updated: 2023/10/19 15:26:32 by twang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =																	\
			sources/mandatory/clean/clean_assets.c							\
			sources/mandatory/clean/clean_windows.c							\
			sources/mandatory/displays/draw/mlx_pixel_get.c					\
			sources/mandatory/displays/draw/mlx_pixel_put.c					\
			sources/mandatory/displays/draw/draw_ceiling_n_floor.c			\
			sources/mandatory/displays/draw/draw_crosshair.c				\
			sources/mandatory/displays/game/raycasting/raycasting.c			\
			sources/mandatory/displays/game/texturing/texturing.c			\
			sources/mandatory/displays/game/core.c							\
			sources/mandatory/displays/motions/check_if_movable.c			\
			sources/mandatory/displays/motions/motions.c					\
			sources/mandatory/displays/viewing_range/viewing_range.c		\
			sources/mandatory/errors/inventory/argument.c					\
			sources/mandatory/errors/inventory/asset.c						\
			sources/mandatory/errors/inventory/file.c						\
			sources/mandatory/errors/inventory/map.c						\
			sources/mandatory/errors/error_switchman.c						\
			sources/mandatory/init/mlx/init.c								\
			sources/mandatory/init/struct/init.c							\
			sources/mandatory/init/switches/key_switchman.c					\
			sources/mandatory/parsing/assets/colors/get_colors.c			\
			sources/mandatory/parsing/assets/colors/utils.c					\
			sources/mandatory/parsing/assets/textures/get_textures.c		\
			sources/mandatory/parsing/assets/asset_switchman.c				\
			sources/mandatory/parsing/assets/asset_checker.c				\
			sources/mandatory/parsing/map/get_map.c							\
			sources/mandatory/parsing/map/map_checker.c						\
			sources/mandatory/parsing/map/utils.c							\
			sources/mandatory/parsing/parsing.c								\
			sources/mandatory/main.c