/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:41:30 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 17:22:15 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_lst **stack)
{
	t_lst	*tmp;
	t_lst	*tmp_run;

	tmp = *stack;
	tmp_run = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp_run->prev = tmp;
	*stack = tmp;
	(*stack)->next = tmp_run;
	(*stack)->prev = NULL;
	redefine_index(*stack, NULL);
}

void	rra(t_lst **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_lst **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rrb\n", 4);
}

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
