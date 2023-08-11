# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_thea.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 14:25:51 by twang             #+#    #+#              #
#    Updated: 2023/08/11 12:05:57 by wangthea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES +=																	\
			sources/mandatory/clean/clean.c									\
			sources/mandatory/errors/inventory/argument.c					\
			sources/mandatory/errors/inventory/asset.c						\
			sources/mandatory/errors/inventory/file.c						\
			sources/mandatory/errors/inventory/map.c						\
			sources/mandatory/errors/error_switchman.c						\
			sources/mandatory/init/mlx/init.c								\
			sources/mandatory/init/struct/init.c							\
			sources/mandatory/parsing/assets/colors/colors_checker.c		\
			sources/mandatory/parsing/assets/colors/get_colors.c			\
			sources/mandatory/parsing/assets/colors/utils.c					\
			sources/mandatory/parsing/assets/textures/get_textures.c		\
			sources/mandatory/parsing/assets/textures/textures_checker.c	\
			sources/mandatory/parsing/assets/asset_switchman.c				\
			sources/mandatory/parsing/map/get_map.c							\
			sources/mandatory/parsing/map/map_checker.c						\
			sources/mandatory/parsing/map/utils.c							\
			sources/mandatory/parsing/parsing.c								\
			sources/mandatory/render/draw/draw_line.c						\
			sources/mandatory/render/draw/draw_square.c						\
			sources/mandatory/render/draw/mlx_pixel_put.c					\
			sources/mandatory/main.c