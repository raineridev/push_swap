/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:05:44 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/21 09:20:06 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"

void numeric_integrity(ps_lst **stack_a, ps_lst **stack_b) 
{
    while(ps_smallest(ps_smallest(*stack_a))->index != 0)
    {
        rra(stack_a);
        redefine_index(*stack_a, *stack_b);
    }
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
    
    while (ps_size(*stack_b) > 0)
    {
        ordering(stack_a, stack_b);
        redefine_index(*stack_a, *stack_b);
    }
    if(ps_smallest(*stack_a)->index != 0)
       numeric_integrity(stack_a, stack_b);  
}
