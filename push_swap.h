/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:59:45 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/02 13:43:23 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Defines 
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef	struct p_lst 
{
	int	num;
	struct p_lst *next;
	struct p_lst *prev;
} ps_lst;

// List Functions -> List/
ps_lst  *ps_create(int num);
void    ps_link(ps_lst **lst, ps_lst **node);
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

#endif