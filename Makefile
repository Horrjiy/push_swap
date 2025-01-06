# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 17:14:53 by mpoplow           #+#    #+#              #
#    Updated: 2025/01/06 19:33:02 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= push_swap

CFILES 	:= src/error.c src/_main_push_swap.c \
		src/s_swap.c src/p_push.c src/r_rotate.c src/rr_revrot.c
			
OFILES := 	$(CFILES:.c=.o)
DFILES :=	$(CFILES:.c=.d)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	@make all -C libft
	@cc $(CFILES) libft/libft.a $(NAME)
	@mkdir O_D_FILES
	 
	@echo "\033[1;32mCREATE PROGRAM: push_swap\033[0m"

clean:
	@echo "\033[1;33mCLEAN push_swap\033[0m"
	@make fclean -C libft
	@rm -f $(OFILES)

fclean: clean
	@echo "\033[1;33mREMOVE PROGRAM: push_swap\033[0m"
	@rm -f $(NAME)

re: clean all

prep: fclean all
	@make clean

.SILENT:
.PHONY: all clean fclean re prep