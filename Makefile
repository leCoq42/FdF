# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/03 13:20:02 by mhaan         #+#    #+#                  #
#    Updated: 2023/04/03 13:40:16 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#GENERAL VARIABLES
NAME := fdf
RM := /bin/rm -rf

#COMPILATION VARIABLES
CFLAGS ?= -Wall -Wextra -Werror
AR := ar -crs

#DIRS AND FILES
INC_DIRS	:=	./includes ./libft_ext/includes
INCLUDES	:=	$(foreach D,$(INC_DIRS),-I$(D))
INC_FILES	:=	./includes/fdf.h

SRC_DIR		:=	./src

SRC			:=

OBJ_DIR		:=	./obj
OBJS		:=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

#DEPENDENCIES:
LIBFT_DIR := ./libft_ext
LIBFT_AR := $(LIBFT_DIR)/libft_ext.a

#RECIPES:
all:	$(NAME)

clean:
		@$(RM) $(OBJ_DIR)
		@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(LIBFT_AR)

re: fclean all

#RULES:
$(NAME): $(OBJS)
		@$(MAKE) -C $(LIBFT_DIR)
		@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_AR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#OTHER:
.PHONY:
		all clean fclean re