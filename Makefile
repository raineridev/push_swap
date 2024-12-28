# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 19:51:22 by mraineri          #+#    #+#              #
#    Updated: 2024/12/28 18:12:14 by mraineri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  := push_swap

CFLAGS := -Wall -Wextra -Werror
FILES := Moviments/push.c Moviments/reverse_rotate.c Moviments/rotate.c Moviments/swap.c \
		 List/ps_create.c List/ps_link.c List/ps_size.c List/ps_free_all.c List/ps_biggest.c List/ps_smallest.c \
		 List/ps_next.c Arguments/add_args.c Arguments/ft_atol.c List/ps_next_biggest.c \
		 Arguments/args_size.c Arguments/trim.c Arguments/find_duplicate.c Arguments/validate_args.c Algorithm/ordering_stack_a.c \
		 Algorithm/moviment_stack_b.c Algorithm/general_managent.c push_swap.c List/ps_target.c Arguments/is_sorted.c Arguments/ft_strlen.c
OBJ_DIR := objects

OBJECTS := $(addprefix $(OBJ_DIR)/, $(notdir $(FILES:.c=.o)))

SRCS := $(FILES)
VPATH := $(dir $(SRCS))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC)  $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

all: $(NAME)

clean: 
	@rm -rf $(OBJ_DIR)
	@echo "\e[44m CLEANING SUCCESSFULLY COMPLETED \e[49m"

fclean:clean
	@rm -rf $(NAME)

re: fclean
	make