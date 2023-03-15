# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 11:01:41 by moudrib           #+#    #+#              #
#    Updated: 2023/03/15 03:00:40 by moudrib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
R = \x1B[91m
G = \x1B[32m
W = \x1B[0m
B = \033[1m
CFLAGS = -Wall -Wextra -Werror -g
OBJDIR = Object_files/
SRC = \
		so_long_mandatory/split.c \
		so_long_mandatory/utils1.c \
		so_long_mandatory/utils2.c \
		so_long_mandatory/so_long.c \
		so_long_mandatory/parsing.c \
		so_long_mandatory/parsing_utils.c \
		so_long_mandatory/get_next_line.c \
		so_long_mandatory/player_movements.c \
		so_long_mandatory/window_management.c \

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -g -o $(NAME)
	@clear
	@echo
	@echo "$(G)So_long compilation done ✔️"
	@echo
	@echo "          $(R)███████$(W)╗ $(R)██████$(W)╗           $(R)██$(W)╗      $(R)██████$(W)╗ $(R)███$(W)╗   $(R)██$(W)╗ $(R)██████$(W)╗"
	@echo "          $(R)██$(W)╔════╝$(R)██$(W)╔═══$(R)██$(W)╗          $(R)██$(W)║     $(R)██$(W)╔═══$(R)██$(W)╗$(R)████$(W)╗  $(R)██$(W)║$(R)██$(W)╔════╝"
	@echo "          $(R)███████$(W)╗$(R)██$(W)║   $(R)██$(W)║          $(R)██$(W)║     $(R)██$(W)║   $(R)██$(W)║$(R)██$(W)╔$(R)██$(W)╗ $(R)██$(W)║$(R)██$(W)║  $(R)███$(W)╗"
	@echo "          $(R)╚════$(W)██$(R)║$(W)██$(R)║   $(W)██$(R)║      $(W)    ██$(R)║     $(W)██$(R)║   $(W)██$(R)║$(W)██$(R)║╚$(W)██$(R)╗$(W)██$(R)║$(W)██$(R)║   $(W)██$(R)║"
	@echo "          $(W)███████$(R)║╚$(W)██████$(R)╔╝$(W) ███████$(R)╗ $(W)███████$(R)╗╚$(W)██████$(R)╔╝$(W)██$(R)║ ╚$(W)████$(R)║╚$(W)██████$(R)╔╝"
	@echo "          $(R)╚══════╝ ╚═════╝  ╚══════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝"
	@echo "                                                                  $(B)$(R)By $(W)$(B)moudrib"
	@echo
	@echo

$(OBJDIR)%.o: %.c so_long.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(G)Compiling: $(W)$<"

bonus:

clean:
	
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
