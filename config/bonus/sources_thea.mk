# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_thea.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twang <twang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 14:25:51 by twang             #+#    #+#              #
#    Updated: 2023/10/19 16:15:54 by twang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES_BONUS +=															\
					sources/bonus/clean/clean_assets.c						\
					sources/bonus/clean/clean_windows.c						\
					sources/bonus/displays/animations/doors.c				\
					sources/bonus/displays/game/texturing/texturing.c		\
					sources/bonus/displays/legend/core.c					\
					sources/bonus/displays/motions/check_if_movable.c		\
					sources/bonus/displays/motions/doors.c					\
					sources/bonus/displays/motions/motions.c				\
					sources/bonus/displays/viewing_range/viewing_range.c	\
					sources/bonus/errors/inventory/argument.c				\
					sources/bonus/errors/inventory/asset.c					\
					sources/bonus/errors/inventory/file.c					\
					sources/bonus/errors/inventory/map.c					\
					sources/bonus/errors/error_switchman.c					\
					sources/bonus/init/legend/init.c						\
					sources/bonus/init/mlx/init.c							\
					sources/bonus/init/struct/init.c						\
					sources/bonus/init/switches/key_switchman.c				\
					sources/bonus/init/switches/mouse_switchman.c			\
					sources/bonus/parsing/assets/animations/init_textures.c	\
					sources/bonus/parsing/assets/animations/utils.c			\
					sources/bonus/parsing/assets/colors/colors_checker.c	\
					sources/bonus/parsing/assets/colors/get_colors.c		\
					sources/bonus/parsing/assets/colors/utils.c				\
					sources/bonus/parsing/assets/doors/set_doors.c			\
					sources/bonus/parsing/assets/textures/get_textures.c	\
					sources/bonus/parsing/assets/asset_switchman.c			\
					sources/bonus/parsing/assets/asset_checker.c			\
					sources/bonus/parsing/map/get_map.c						\
					sources/bonus/parsing/map/map_checker.c					\
					sources/bonus/parsing/map/utils.c						\
					sources/bonus/parsing/parsing.c							\
					sources/bonus/main.c