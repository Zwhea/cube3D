# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 15:45:26 by mmosca            #+#    #+#              #
#    Updated: 2023/08/02 15:47:31 by mmosca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## -- Includes -----------------------------------------------------------------

include config/headers.mk
include config/sources.mk

## -- Properties ---------------------------------------------------------------

NAME = unit_testing.a
CFLAGS = -Wall -Wextra -Werror -I includes
ARFLAGS = rcs

BIN_DIR = bin
BUILD_DIR = build

OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:.c=.o))
OBJECTS_DIR = $(sort $(dir $(OBJECTS)))

## -- Rules --------------------------------------------------------------------

.SUFFIXES:
.SUFFIXES: .c .o

.PHONY: all clean dirs fclean re norm

# Compile the entire program.
all: $(BIN_DIR)/$(NAME)

$(BUILD_DIR)/%.o: %.c $(HEADERS) | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

# Create bin and build directories.
dirs:
	@mkdir -p $(BIN_DIR) $(OBJECTS_DIR)

# Delete all objects files that are normally created by building the program.
clean:
	$(RM) $(OBJECTS)

# Delete objects files and program file created by building the program.
fclean: clean
	$(RM) $(BIN_DIR)/$(NAME)

# Clean and recompile the entire program.
re: fclean
	@$(MAKE) all

# Run the `norminette` program.
norm:
	@norminette
