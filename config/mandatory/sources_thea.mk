# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_thea.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 14:25:51 by twang             #+#    #+#              #
#    Updated: 2023/08/09 16:41:18 by wangthea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES +=																	\
			sources/mandatory/clean/clean.c									\
			sources/mandatory/init/mlx/init_mlx.c							\
			sources/mandatory/init/struct/init_struct.c						\
			sources/mandatory/parsing/assets/colors/colors_checker.c		\
			sources/mandatory/parsing/assets/colors/get_colors.c			\
			sources/mandatory/parsing/assets/colors/utils.c					\
			sources/mandatory/parsing/assets/textures/get_textures.c		\
			sources/mandatory/parsing/assets/textures/textures_checker.c	\
			sources/mandatory/parsing/assets/asset_switchman.c				\
			sources/mandatory/parsing/errors/inventory/argument.c			\
			sources/mandatory/parsing/errors/inventory/asset.c				\
			sources/mandatory/parsing/errors/inventory/file.c				\
			sources/mandatory/parsing/errors/inventory/map.c				\
			sources/mandatory/parsing/errors/error_switchman.c				\
			sources/mandatory/parsing/map/get_map.c							\
			sources/mandatory/parsing/map/map_checker.c						\
			sources/mandatory/parsing/map/utils.c							\
			sources/mandatory/parsing/utils/checkers.c						\
			sources/mandatory/parsing/utils/prints.c						\
			sources/mandatory/parsing/parsing.c								\
			sources/mandatory/main.c