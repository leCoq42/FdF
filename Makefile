# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/03 13:20:02 by mhaan         #+#    #+#                  #
#    Updated: 2023/08/18 16:23:57 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES
NAME := fdf
RM := /bin/rm -rf

#COMPILATION VARIABLES
CFLAGS ?= -Wall -Wextra -Werror

ifdef OPTIM
	CFLAGS += -O3 -flto -march=native
endif

AR := ar -crs

#DEPENDENCIES:
LIBMLX		:= ./libs/MLX42
LIBFT		:= ./libs/libft_ext
LIBS		:= $(LIBFT)/libft_ext.a $(LIBMLX)/build/libmlx42.a -lglfw -L"/Users/$(USER)/homebrew/Cellar/glfw/3.3.8/lib/"

#DIRS AND FILES
HEADERS		:=	-I./includes -I$(LIBMLX)/include/MLX42 -I$(LIBFT)/includes

SRC_DIR		:=	./src
SRC			:=	fdf.c \
				init.c \
				camera.c \
				error_funcs.c \
				parser_funcs.c \
				map.c draw.c \
				utils.c \
				user_input.c \
				user_input2.c \
				bresenham_line.c \
				wu_line.c \
				menu.c \
				color.c \
				projection.c \
				free.c

OBJ_DIR		:=	./obj
OBJS		:=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

#RECIPES:
all:	libmlx libft $(NAME)

optim:
	@$(MAKE) OPTIM=1 all

reoptim:
	@$(MAKE) fclean
	$(MAKE) optim

libmlx:
		@cmake $(LIBMLX) -B $(LIBMLX)/build && cmake --build $(LIBMLX)/build -j
# @cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j

libft:
	@make -j -C $(LIBFT)

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT)
	@rm -rf $(LIBMLX)/build/

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT)

re:		clean all

#RULES:
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
# @$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
#&& printf "Compiling: $(notdir $<)\n"

#OTHER:
.PHONY:	all, clean, fclean, re, libmlx
