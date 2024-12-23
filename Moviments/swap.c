/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:59:28 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 16:28:50 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_lst **stack)
{
	t_lst	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = tmp;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	tmp->prev = *stack;
}

void	sa(t_lst **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_lst **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_lst **stack_a, t_lst **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
