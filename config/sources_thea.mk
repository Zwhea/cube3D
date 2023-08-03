# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_thea.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twang <twang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 14:25:51 by twang             #+#    #+#              #
#    Updated: 2023/08/03 13:55:41 by twang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES +=																	\
			sources/parsing/assets/colors/get_colors.c						\
			sources/parsing/assets/textures/get_textures.c					\
			sources/parsing/assets/asset_switchman.c						\
			sources/parsing/errors/inventory/argument.c						\
			sources/parsing/errors/inventory/asset.c						\
			sources/parsing/errors/inventory/file.c							\
			sources/parsing/errors/inventory/map.c							\
			sources/parsing/errors/error_switchman.c						\
			sources/parsing/map/get_map.c									\
			sources/parsing/map/utils.c										\
			sources/parsing/utils/checkers.c								\
			sources/parsing/utils/clean.c									\
			sources/parsing/utils/prints.c									\
			sources/parsing/parsing.c										\
			sources/main.c