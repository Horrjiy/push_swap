# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 17:14:53 by mpoplow           #+#    #+#              #
#    Updated: 2025/01/12 12:25:01 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	FILES																		#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

CFILES	:= src/_main_push_swap.c \
		src/error.c src/free.c \
		src/argv_convert.c \
		src/s_swap.c src/p_push.c src/r_rotate.c src/rr_revrot.c

OFILES	= $(CFILES:.c=.o)
DFILES	= $(CFILES:.c=.d)

CFLAGS	:= -Wall -Wextra -Werror -MMD

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	RULES																		#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

%.o: %.c
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES) $(DFILES)
	make all -C libft
	$(CC) $(OFILES) libft/libft.a -o $(NAME)
	@echo "\033[1;32mCREATE PROGRAM: push_swap\033[0m"
	@mkdir -p src/O_D_FILES
	@mv $(OFILES) $(DFILES) src/O_D_FILES

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

.SILENT:
.PHONY: all clean fclean re prep