/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:05:44 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/24 17:10:01 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"

void numeric_integrity(ps_lst **stack_a, ps_lst **stack_b) 
{
    while(ps_bigest(*stack_a)->index != (ps_size(*stack_a) - 1))
    {
        rra(stack_a);
        redefine_index(*stack_a, *stack_b);
    }
    if (ps_smallest(*stack_a)->index == 1) 
        sa(stack_a);

}

void ordering_stack_a(ps_lst **stack_a, ps_lst **stack_b)
{
    redefine_index(*stack_a, *stack_b);
    while (ps_bigest(*stack_a)->index != 2)
    {
        ra(stack_a);
        redefine_index(*stack_a, *stack_b);
    }
    
    if (ps_smallest(*stack_a)->index == 1) 
        sa(stack_a);
    redefine_index(*stack_a, *stack_b);
    
    while (ps_size(*stack_b) != 1)
    {
        ordering(stack_a, stack_b);
        redefine_index(*stack_a, *stack_b);
    }
    numeric_integrity(stack_a, stack_b);
    pa(stack_b, stack_a);
    // numeric_integrity(stack_a, stack_b);
    // numeric_integrity(stack_a);
}
