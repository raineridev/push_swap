/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:59:21 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 17:22:12 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tmp;
	t_lst	*tmp_a;

	tmp = *stack_b;
	tmp_a = (*stack_a)->next;
	*stack_b = *stack_a;
	(*stack_b)->next = tmp;
	*stack_a = tmp_a;
	if ((*stack_b)->next)
		(*stack_b)->next->prev = *stack_b;
	tmp = *stack_b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = NULL;
	if (tmp_a)
		tmp_a->prev = NULL;
	redefine_index(*stack_a, *stack_b);
}

void	pb(t_lst **stack_a, t_lst **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	pa(t_lst **stack_b, t_lst **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}
