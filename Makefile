# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 19:51:22 by mraineri          #+#    #+#              #
#    Updated: 2024/11/17 23:18:57 by mraineri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  := push_swap
 
FILES := push_swap.c Moviments/push.c Moviments/reverse_rotate.c Moviments/rotate.c Moviments/swap.c \
		 List/ps_create.c List/ps_link.c List/ps_size.c List/ps_free_all.c List/ps_bigest.c List/ps_smallest.c \
		 List/ps_soon.c Arguments/add_args.c Arguments/ft_atoi.c Algorithm/cost_managent.c List/ps_soon_bigest.c \
		 Arguments/args_size.c Arguments/trim.c Arguments/find_duplicate.c Arguments/validate_args.c

all: 
	@cc -Wall -Wextra -Werror $(FILES) -o $(NAME)
	@echo "\e[42m SUCCESSFUL COMPILATION \e[49m"

clean: 
	@rm -rf $(NAME)
	@echo "\e[44m CLEANING SUCCESSFULLY COMPLETED \e[49m"