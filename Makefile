# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/03 13:20:02 by mhaan         #+#    #+#                  #
#    Updated: 2023/04/03 17:34:45 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES
NAME := fdf
RM := /bin/rm -rf

#COMPILATION VARIABLES
CFLAGS ?= -Wall -Wextra -Werror
AR := ar -crs

#DIRS AND FILES
HEADERS		:=	-I ./includes -I $(LIBMLX)/include -I $(LIBFT_DIR)/includes

SRC_DIR		:=	./src
SRC			:=	main.c

OBJ_DIR		:=	./obj
OBJS		:=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

#DEPENDENCIES:
LIBMLX		:= ./libs/MLX42
LIBFT_DIR	:= ./libs/libft_ext
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT_DIR)/libft_ext.a

#RECIPES:
all:	libmlx $(NAME)

libmlx:
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j

clean:
		@$(RM) $(OBJ_DIR)
		@$(MAKE) clean -C $(LIBFT_DIR)
		@rm -rf $(LIBMLX)/build/

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(LIBFT_AR)

re:		clean all

#RULES:
# $(NAME): $(OBJS)
# @$(MAKE) -C $(LIBFT_DIR)
# @$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_AR) -o $(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) libmlx42.a -lglfw -L "/Users/$USER/.brew/opt/glfw/lib/" -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

# @$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#OTHER:
.PHONY:	all, clean, fclean, re, libmlx
