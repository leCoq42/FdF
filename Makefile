# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/03 13:20:02 by mhaan         #+#    #+#                  #
#    Updated: 2023/04/24 12:03:03 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES
NAME := fdf
RM := /bin/rm -rf

#COMPILATION VARIABLES
CFLAGS ?= -Wall -Wextra -Werror
AR := ar -crs

#DEPENDENCIES:
LIBMLX		:= ./libs/MLX42
LIBFT		:= ./libs/libft_ext
LIBS		:= $(LIBFT)/libft_ext.a $(LIBMLX)/build/libmlx42.a -lglfw -L "/Users/$(USER)/homebrew/Cellar/glfw/3.3.8/lib/"

#DIRS AND FILES
HEADERS		:=	-I./includes -I$(LIBMLX)/include/MLX42 -I$(LIBFT)/includes

SRC_DIR		:=	./src
SRC			:=	fdf.c \
				init.c \
				point.c \
				camera.c \
				error_funcs.c \
				parser_funcs.c \
				map.c draw.c \
				utils.c \
				user_input.c \
				bresenham_line.c \
				wu_line.c

OBJ_DIR		:=	./obj
OBJS		:=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

#RECIPES:
# all:	libmlx libft $(NAME)
all:	$(NAME)

libmlx:
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j

libft:
		@make -C $(LIBFT)

clean:
		@$(RM) $(OBJ_DIR)
# @rm -rf $(LIBMLX)/build/
# @$(MAKE) clean -C $(LIBFT)

fclean: clean
		@$(RM) $(NAME)
		@$(MAKE) fclean -C $(LIBFT)

re:		clean all

#RULES:
$(NAME): $(OBJS)
		$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

#OTHER:
.PHONY:	all, clean, fclean, re, libmlx
