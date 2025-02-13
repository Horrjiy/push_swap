# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 17:14:53 by mpoplow           #+#    #+#              #
#    Updated: 2025/02/07 18:05:36 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

CFLAGS	:= -Wall -Wextra -Werror -MMD
# -fsanitize=address -g

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	FILES																		#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

CFILES	:= $(addprefix src/, \
		_main_push_swap.c \
		error_free.c \
		argv_convert.c list_ft.c \
		check_sorted.c \
		find_smallest_largest.c target.c cost_calculation.c \
		turksort.c sort_three_four.c \
		s_swap.c p_push.c r_rotate.c rr_revrotate.c )

OFILES	= $(addprefix src/O_D_FILES/, $(notdir $(CFILES:.c=.o)))
DFILES	= $(addprefix src/O_D_FILES/, $(notdir $(CFILES:.c=.d)))

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	RULES																		#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

all: $(NAME)

$(NAME): $(OFILES) $(DFILES)
	@make all -C libft
	@$(CC) $(OFILES) libft/libft.a -o $(NAME)
	@echo "\033[1;32mCREATE PROGRAM: push_swap\033[0m"

src/O_D_FILES/%.o: src/%.c | src/O_D_FILES
	@$(CC) $(CFLAGS) -MMD -MP -g -c $< -o $@

src/O_D_FILES:
	@mkdir -p $@

clean:
	@echo "\033[1;33mCLEAN push_swap\033[0m"
	@make fclean -C libft
	@rm -f $(OFILES) $(DFILES)
	@rm -rf src/O_D_Files

fclean: clean
	@echo "\033[1;33mREMOVE PROGRAM: push_swap\033[0m"
	@rm -f $(NAME)

re: clean all

prep: fclean all
	make clean

.SILENT:  $(OFILES) $(DFILES)
.PHONY: all clean fclean re prep