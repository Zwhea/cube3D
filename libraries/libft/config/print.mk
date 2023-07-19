# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    print.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twang <twang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 09:43:34 by twang             #+#    #+#              #
#    Updated: 2023/07/19 17:08:31 by twang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--colors----------------------------------------------------------------------#

GREY		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
ORANGE		=	\033[33m
BLUE		=	\033[34m
PURPLE		=	\033[35m
LIGHTBLUE	=	\033[36m
WHITE		=	\033[37m

#--styles----------------------------------------------------------------------#

END			=	\033[0m
BOLD		=	\033[1m
ITALIC		=	\033[3m
UNDERLINE	=	\033[4m
DEL_LINE	=	\033[2K\r

#--print rules-----------------------------------------------------------------#

define    PRINT_CLEAN
    printf "[ ${RED}removing${END} ]\t${LIGHTBLUE}binaries files${END}\n"
endef

define    PRINT_FCLEAN
    printf "[ ${RED}removing${END} ]\t${LIGHTBLUE}executable file${END}\n\n"
endef

define    PRINT_COMPILING
    printf "%-95b%b" "[ ${PURPLE}compiling${END} ]\t${LIGHTBLUE}$<${END}" "${GREEN}[✓]${END}\n"
endef

define    PRINT_CREATING
    printf "%-95b%b" "\n[ ${PURPLE}creating${END} ]\t${LIGHTBLUE}$@${END}" "${RED}[✓]${END}\n\n"
endef

define LINE
    printf "\n              ----------------------------\n\n"
endef
