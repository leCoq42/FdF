# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/03 13:20:02 by mhaan         #+#    #+#                  #
#    Updated: 2023/04/05 11:46:24 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES
NAME := fdf
RM := /bin/rm -rf

#COMPILATION VARIABLES
CFLAGS ?= -Wall -Wextra -Werror
AR := ar -crs

#DIRS AND FILES
LIBMLX		:= ./libs/MLX42
LIBFT		:= ./libs/libft_ext
LIBS		:= $(LIBFT)/libft_ext.a $(LIBMLX)/build/libmlx42.a -lglfw -L "/Users/$(USER)/homebrew/Cellar/glfw/3.3.8/lib/"

HEADERS		:=	-I./includes -I$(LIBMLX)/include/MLX42 -I$(LIBFT)/includes

SRC_DIR		:=	./src
SRC			:=	spark.c

OBJ_DIR		:=	./obj
OBJS		:=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

#DEPENDENCIES:

#RECIPES:
all:	libmlx libft $(NAME)

libmlx:
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j

libft:
		@make -C $(LIBFT)

clean:
		@$(RM) $(OBJ_DIR)
		@rm -rf $(LIBMLX)/build/
		@$(MAKE) clean -C $(LIBFT)

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
