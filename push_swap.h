/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:59:45 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/09 21:43:57 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Defines 
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef	struct p_lst 
{
	int	num;
	int	index;
	int	cost;
	int total_cost;
	struct p_lst *target;
	struct p_lst *next;
	struct p_lst *prev;
} ps_lst;

// List Functions -> List/
ps_lst  *ps_create(int num);
ps_lst 	*ps_soon(ps_lst *node_a, ps_lst *stack_b);
ps_lst 	*ps_bigest(ps_lst *stack);
ps_lst 	*ps_smallest(ps_lst *stack);
ps_lst	*ps_soon_bigest(ps_lst *stack_a, ps_lst *stack_b);
int		ps_size(ps_lst *stack);
void	ps_free_all(ps_lst *list);
void    ps_link(ps_lst **lst, ps_lst **node, int index);
// List Moviments -> Moviments/
/// Push Moviment -> push.c
void    push(ps_lst **stack_a, ps_lst **stack_b);
void	pa(ps_lst **stack_a, ps_lst **stack_b);
void	pb(ps_lst **stack_b, ps_lst **stack_a);
/// Swap Moviment -> swap.c
void	swap(ps_lst **stack);
void	sa(ps_lst **stack_a);
void	sb(ps_lst **stack_b);
void	ss(ps_lst **stack_a, ps_lst **stack_b);
/// Rotate Moviment -> rotate.c
void rotate(ps_lst **stack);
void    ra(ps_lst **stack);
void    rb(ps_lst **stack);
void    rr(ps_lst **stack_a, ps_lst **stack_b);
/// Reverse Rotate Moviment -> reverse_rotate.c
void reverse_rotate(ps_lst **stack);
void    rra(ps_lst **stack_a);
void    rrb(ps_lst **stack_a);
void    rrr(ps_lst **stack_a, ps_lst **stack_b);
///
// Arguments
int		ft_atoi(char *str);
void    validate_args(int size, int *argc);
void	add_args(ps_lst **head, int *args, int size);
int 	args_size(char *argc[]);
int 	find_duplicate(int *arr, int size);
int		*trim(int argv,char *argc[]);
// Cost
void	ps_target(ps_lst *stack_a, ps_lst *stack_b);
void	redefine_index(ps_lst *stack_a, ps_lst *stack_b);
// Algorithmn
void	moviment_stack_b(ps_lst **stack_a, ps_lst **stack_b);
void	ordering_stack_a(ps_lst **stack_a, ps_lst **stack_b);
void	ordering(ps_lst **stack_a, ps_lst **stack_b);
void	make_moviment(ps_lst **stack_a, ps_lst **stack_b);
void	cost_stack(ps_lst *stack);
void 	redefine_index(ps_lst *stack_a, ps_lst *stack_b);
void	ps_target(ps_lst *stack_a, ps_lst *stack_b);
ps_lst	*more_cheap(ps_lst *stack);
#endif