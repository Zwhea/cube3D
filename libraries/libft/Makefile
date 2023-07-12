# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 11:55:03 by wangthea          #+#    #+#              #
#    Updated: 2023/07/04 12:29:57 by wangthea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		config/headers.mk
include		config/print.mk
include		config/sources.mk

.SILENT	:

#--static library--------------------------------------------------------------#

NAME	=	libft.a

#--compilation flags-----------------------------------------------------------#

CFLAGS	=	-Wall -Wextra -Werror -I .

#--directory variables---------------------------------------------------------#

OBJ_DIR	=	.objs

#--objects---------------------------------------------------------------------#

OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

#--compilation rules-----------------------------------------------------------#

all		:	$(NAME)

$(NAME)	:	$(OBJECTS)
			$(AR) rcs $@ $^
			$(PRINT_CREATING)

#--objects's compilation rule--------------------------------------------------#

$(OBJ_DIR)/%.o:	%.c $(HEADERS)
				mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@
				$(PRINT_COMPILING)
	
#--clean, fclean & re----------------------------------------------------------#

clean	:
			$(RM) -rf $(OBJECTS)
			$(PRINT_CLEAN)

fclean	:	
			$(MAKE) clean 
			$(RM) $(NAME)
			$(PRINT_FCLEAN)

re		:	
			clear
			$(MAKE) fclean
			$(MAKE) all
	
#--PHONY-----------------------------------------------------------------------#

.PHONY: all clean fclean re
