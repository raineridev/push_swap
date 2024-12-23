/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:27:55 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 16:28:50 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_lst **stack)
{
	t_lst	*tmp;
	t_lst	*tmp_run;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp_run = *stack;
	while (tmp_run->next)
		tmp_run = tmp_run->next;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp_run->next = tmp;
	tmp->next = NULL;
	tmp->prev = tmp_run;
}

void	ra(t_lst **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_lst **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_lst **stack_a, t_lst **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
