# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 19:51:22 by mraineri          #+#    #+#              #
#    Updated: 2024/10/31 11:34:41 by mraineri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  := push_swap
 
FILES := push_swap.c Moviments/push.c Moviments/reverse_rotate.c Moviments/rotate.c Moviments/swap.c \
		 List/ps_create.c List/ps_link.c List/ps_size.c List/ps_bigest.c Arguments/add_args.c Arguments/ft_atoi.c Algorithm/cost_managent.c

all: 
	@cc -Wall -Wextra -Werror $(FILES) -o $(NAME)
	@echo "\e[42m SUCCESSFUL COMPILATION \e[49m"

clean: 
	@rm -rf $(NAME)
	@echo "\e[44m CLEANING SUCCESSFULLY COMPLETED \e[49m"