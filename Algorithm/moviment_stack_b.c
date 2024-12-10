/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:07:03 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/22 20:11:03 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	moviment_stack_b(ps_lst **stack_a, ps_lst **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if ((*stack_b)->num != ps_bigest(*stack_b)->num)
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
	while ((ps_bigest(*stack_b)->index != 0))
	{
		rrb(stack_b);
		redefine_index(*stack_a, *stack_b);
	}
	while ((ps_bigest(*stack_b)->index != 0))
	{
		rrb(stack_b);
		redefine_index(*stack_a, *stack_b);
	}
}
