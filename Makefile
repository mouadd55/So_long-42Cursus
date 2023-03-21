# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 11:01:41 by moudrib           #+#    #+#              #
#    Updated: 2023/03/21 19:06:03 by moudrib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
BONUS		= solong_bonus
CC			= cc
R			= \x1B[91m
G			= \x1B[32m
W			= \x1B[0m
B			= \033[1m
CFLAGS		= -Wall -Wextra -Werror -g
OBJDIR		= Object_files/
SRC			= \
				so_long_mandatory/split.c \
				so_long_mandatory/utils1.c \
				so_long_mandatory/utils2.c \
				so_long_mandatory/so_long.c \
				so_long_mandatory/parsing.c \
				so_long_mandatory/valid_path.c \
				so_long_mandatory/parsing_utils.c \
				so_long_mandatory/get_next_line.c \
				so_long_mandatory/player_movements.c \
				so_long_mandatory/window_management.c \

BONUS_SRC	= \
				so_long_bonus/split_bonus.c \
				so_long_bonus/utils1_bonus.c \
				so_long_bonus/utils2_bonus.c \
				so_long_bonus/utils3_bonus.c \
				so_long_bonus/so_long_bonus.c \
				so_long_bonus/parsing_bonus.c \
				so_long_bonus/animation_bonus.c \
				so_long_bonus/valid_path_bonus.c \
				so_long_bonus/parsing_utils_bonus.c \
				so_long_bonus/get_next_line_bonus.c \
				so_long_bonus/player_movements_bonus.c \
				so_long_bonus/window_management_bonus.c \

OBJ 		= $(addprefix $(OBJDIR),$(SRC:.c=.o))
BONUS_OBJ	= $(addprefix $(OBJDIR),$(BONUS_SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
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

$(OBJDIR)%.o: %.c so_long_mandatory/so_long.h so_long_bonus/so_long_bonus.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(G)Compiling: $(W)$<"

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJ)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(BONUS_OBJ) -o $(BONUS)
	@clear
	@echo
	@echo "$(G)So_long bonus compilation done ✔️"
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

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
