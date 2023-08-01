# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twang <twang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 14:09:46 by twang             #+#    #+#              #
#    Updated: 2023/07/31 10:29:58 by twang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config/print.mk
include config/sources_arthur.mk
include config/headers_arthur.mk
include config/sources_thea.mk
include config/headers_thea.mk

.SILENT:

#--variables-------------------------------------------------------------------#

NAME		=	cub3D
DEBUG		=	no
VALGRIND	=	no
OS			=	$(shell uname)
WHO			=	$(shell whoami)
AASCEDU		=	\e]8;;https://profile.intra.42.fr/users/aascedu\a\e[34maascedu\e[34m\e]8;;\a
TWANG		=	\e]8;;https://profile.intra.42.fr/users/twang\a\e[34mtwang\e[34m\e]8;;\a

#--includes & libraries--------------------------------------------------------#

INC_DIR		=	incs/
LIB_DIR		=	libraries
LIBFT_DIR	=	$(LIB_DIR)/libft

ifeq ($(OS), Darwin)
MLX_DIR 	=	$(LIB_DIR)/mlx_mac
else ifeq ($(OS), Linux)
MLX_DIR 	=	$(LIB_DIR)/mlx_linux
endif

#--sources & objects-----------------------------------------------------------#

SRC_DIR		=	sources
OBJ_DIR		=	.objs

#--flags-----------------------------------------------------------------------#

CFLAGS		=	-Wall -Wextra -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(INC_DIR)arthur -I $(INC_DIR)thea #-Werror

#--mlx flags-------------------------------------------------------------------#

MLX_FLAGS	=	-L $(MLX_DIR)

ifeq ($(OS), Darwin)
MLX_FLAGS 	+= -framework OpenGL -framework AppKit
else ifeq ($(OS), Linux)
MLX_FLAGS 	+= -l m -l Xext -l X11 -I $(MLX_DIR)
endif

#--debug flags-----------------------------------------------------------------#

DFLAGS		=	-g3 -fsanitize=address

ifeq ($(DEBUG), yes)
CFLAGS 		+=	$(DFLAGS)
endif

#--leaks flags-----------------------------------------------------------------#

LEAKS	=	valgrind --leak-check=full --track-fds=yes

#--define flags----------------------------------------------------------------#

ifeq ($(OS), Darwin)
CFLAGS 		+=	-DMACOS
endif

ifeq ($(WHO), twang)
WHO 	=	Théa 🐼
else ifeq ($(WHO), aascedu)
WHO 	=	Arthur 🦋
else
WHO		=	!
endif

#--libs------------------------------------------------------------------------#

LIBFT	=	$(LIBFT_DIR)/libft.a
MLX		=	$(MLX_DIR)/libmlx.a

#--objects---------------------------------------------------------------------#

OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

#--compilation rules-----------------------------------------------------------#

all:
	$(MAKE) header
	$(MAKE) lib
	$(MAKE) $(NAME) -j
	$(MAKE) welcome

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $^ $(CFLAGS) $(LIBFT) $(MLX) -o $@ $(MLX_FLAGS)
	$(PRINT_CREATING)

$(OBJ_DIR)/%.o: %.c $(HEADERS) 
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	$(PRINT_COMPILING)

#--libs, debugs----------------------------------------------------------------#

lib:
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)

debug:
	$(MAKE) re -j DEBUG=yes

leaks:
	clear
	$(MAKE) -j VALGRIND=yes
	$(LEAKS) ./cub3D assets/maps/map.cub

#--print header----------------------------------------------------------------#

header:
	printf "\n${PURPLE}project:\t${END}${BLUE}cub3D${END}\n"
	printf "${PURPLE}author:\t\t${END}${BLUE}${AASCEDU} && ${TWANG}${END}\n"
	printf "${PURPLE}leaks mode:\t${END}${BLUE}${VALGRIND}${END}\n"
	printf "${PURPLE}debug mode:\t${END}${BLUE}${DEBUG}${END}\n"
	printf "${PURPLE}compiler:\t${END}${BLUE}${CC}${END}\n"
	printf "${PURPLE}flags:\t\t${END}${BLUE}${CFLAGS}${END}\n"
	printf "${PURPLE}date:\t\t${END}${BLUE}2023/${END}\n"
	printf "              ____________________________\n\n"

welcome:
	printf "\n${GREEN}Welcome ${WHO}${END}\n\n"

#--re, clean, fclean & norminette----------------------------------------------#

re:
	clear
	$(MAKE) fclean
	$(MAKE) -j all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) -rf $(OBJECTS)
	$(RM) -rf $(OBJ_DIR)
	$(PRINT_CLEAN)

fclean:
	clear
	$(MAKE) clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(PRINT_FCLEAN)

norm:
	norminette $(LIBFT_DIR) $(INC_DIR) $(SRC_DIR)

#--PHONY-----------------------------------------------------------------------#

.PHONY: all lib debug leaks header welcome re clean fclean norm