/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:07:03 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/26 16:17:40 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	send_two(t_lst **stack_a, t_lst **stack_b)
{
	if (ps_size(*stack_a) > 4)
	{
		pb(stack_a, stack_b);
	}
	pb(stack_a, stack_b);
}

void	moviment_stack_b(t_lst **stack_a, t_lst **stack_b)
{
	send_two(stack_a, stack_b);
	if ((*stack_b)->num != ps_biggest(*stack_b)->num)
		sb(stack_b);
	if (ps_smallest(*stack_a)->index == 1)
		sa(stack_a);
	redefine_index(*stack_a, *stack_b);
	while (ps_size(*stack_a) > 3)
	{
		redefine_index(*stack_a, *stack_b);
		cost_stack(*stack_a);
		cost_stack(*stack_b);
		ps_target(*stack_a, *stack_b);
		make_moviment(stack_a, stack_b);
	}
	while ((ps_biggest(*stack_b)->index != 0))
	{
		rrb(stack_b);
		redefine_index(*stack_a, *stack_b);
	}
	while ((ps_biggest(*stack_b)->index != 0))
	{
		rrb(stack_b);
		redefine_index(*stack_a, *stack_b);
	}
}
