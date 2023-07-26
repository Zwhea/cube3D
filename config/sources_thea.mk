# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_thea.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 14:25:51 by twang             #+#    #+#              #
#    Updated: 2023/07/25 12:58:39 by wangthea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES +=																	\
			sources/parsing/assets/get_assets.c								\
			sources/parsing/errors/inventory/argument.c						\
			sources/parsing/errors/inventory/asset.c						\
			sources/parsing/errors/inventory/file.c						\
			sources/parsing/errors/inventory/map.c							\
			sources/parsing/errors/error_switchman.c						\
			sources/parsing/file/get_file.c									\
			sources/parsing/file/utils.c									\
			sources/parsing/map/get_map.c									\
			sources/parsing/utils/checkers.c								\
			sources/parsing/utils/prints.c									\
			sources/parsing/parsing.c										\
			sources/main.c