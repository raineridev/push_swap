/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:59:45 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 17:23:05 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Defines 
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct p_lst
{
	int				num;
	int				index;
	int				cost;
	int				total_cost;
	struct p_lst	*target;
	struct p_lst	*next;
	struct p_lst	*prev;
}	t_lst;

// List Functions -> List/
t_lst	*ps_create(int num);
t_lst	*ps_soon(t_lst *node_a, t_lst *stack_b);
t_lst	*ps_bigest(t_lst *stack);
t_lst	*ps_smallest(t_lst *stack);
t_lst	*ps_soon_bigest(t_lst *stack_a, t_lst *stack_b);
int		ps_size(t_lst *stack);
void	ps_free_all(t_lst *list);
void	ps_target(t_lst *stack_a, t_lst *stack_b);
void	ps_link(t_lst **lst, t_lst **node, int index);
// List Moviments -> Moviments/
/// Push Moviment -> push.c
void	push(t_lst **stack_a, t_lst **stack_b);
void	pa(t_lst **stack_a, t_lst **stack_b);
void	pb(t_lst **stack_b, t_lst **stack_a);
/// Swap Moviment -> swap.c
void	swap(t_lst **stack);
void	sa(t_lst **stack_a);
void	sb(t_lst **stack_b);
void	ss(t_lst **stack_a, t_lst **stack_b);
/// Rotate Moviment -> rotate.c
void	rotate(t_lst **stack);
void	ra(t_lst **stack);
void	rb(t_lst **stack);
void	rr(t_lst **stack_a, t_lst **stack_b);
/// Reverse Rotate Moviment -> reverse_rotate.c
void	reverse_rotate(t_lst **stack);
void	rra(t_lst **stack_a);
void	rrb(t_lst **stack_a);
void	rrr(t_lst **stack_a, t_lst **stack_b);
///
// Arguments
int		ft_atoi(char *str);
void	validate_args(int size, int *argc);
void	add_args(t_lst **head, int *args, int size);
int		args_size(char *argc[]);
int		find_duplicate(int *arr, int size);
int		*trim(int argv, char *argc[]);
// Cost
void	ps_target(t_lst *stack_a, t_lst *stack_b);
void	redefine_index(t_lst *stack_a, t_lst *stack_b);
// Algorithmn
void	moviment_stack_b(t_lst **stack_a, t_lst **stack_b);
void	ordering_stack_a(t_lst **stack_a, t_lst **stack_b);
void	ordering(t_lst **stack_a, t_lst **stack_b);
void	make_moviment(t_lst **stack_a, t_lst **stack_b);
void	cost_stack(t_lst *stack);
void	redefine_index(t_lst *stack_a, t_lst *stack_b);
void	ps_target(t_lst *stack_a, t_lst *stack_b);
t_lst	*more_cheap(t_lst *stack);
#endif
