/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generel_managent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:22:52 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 16:28:50 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_target(t_lst *stack_a, t_lst *stack_b)
{
	t_lst	*tmp_a;

	if (!stack_a || !stack_b)
		return ;
	tmp_a = stack_a;
	while (tmp_a)
	{
		tmp_a->target = ps_soon(tmp_a, stack_b);
		tmp_a = tmp_a->next;
	}
}

void	redefine_index(t_lst *stack_a, t_lst *stack_b)
{
	t_lst	*tmp_a;
	t_lst	*tmp_b;
	int		i;

	tmp_a = stack_a;
	tmp_b = stack_b;
	i = 0;
	if ((tmp_b && tmp_a) && (tmp_a->prev || tmp_b->prev))
	{
		while (tmp_a->prev)
			tmp_a = tmp_a->prev;
		while (tmp_b->prev)
			tmp_b = tmp_b->prev;
	}
	while (tmp_a)
	{
		tmp_a->index = i++;
		tmp_a = tmp_a->next;
	}
	i = 0;
	while (tmp_b)
	{
		tmp_b->index = i++;
		tmp_b = tmp_b->next;
	}
}

void	cost_stack(t_lst *stack)
{
	t_lst	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index == 0)
			tmp->cost = 0;
		else if (tmp->index == 1)
			tmp->cost = tmp->index;
		else if ((tmp->index - 1) <= (ps_size(tmp) - tmp->index))
			tmp->cost = tmp->index;
		else if ((tmp->index - 1) > (ps_size(tmp) - tmp->index))
			tmp->cost = ps_size(stack) - tmp->index;
		tmp = tmp->next;
	}
}

t_lst	*more_cheap(t_lst *stack)
{
	t_lst	*cheap_node;
	t_lst	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	cheap_node = stack;
	while (tmp)
	{
		if ((tmp->cost + tmp->target->cost) < \
			(cheap_node->cost + cheap_node->target->cost))
			cheap_node = tmp;
		tmp = tmp->next;
	}
	return (cheap_node);
}

void	make_moviment(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tmp;

	tmp = more_cheap(*stack_a);
	while (tmp->index != 0)
	{
		if ((tmp->index) <= (ps_size(tmp) - tmp->index) && (tmp->index == tmp->target->index))
			rr(stack_a, stack_b);
		else if ((tmp->index) <= (ps_size(tmp) - tmp->index))
			ra(stack_a);
		else if ((tmp->index) > (ps_size(tmp) - tmp->index) && (tmp->index == tmp->target->index))
			rrr(stack_a, stack_b);
		else if ((tmp->index) > (ps_size(tmp) - tmp->index))
			rra(stack_a);
		redefine_index(tmp, tmp->target);
	}
	while (tmp->target->index != 0)
	{
		if ((tmp->target->index) <= (ps_size(tmp->target) - tmp->target->index))
			rb(stack_b);
		else if ((tmp->target->index) > (ps_size(tmp->target) - tmp->target->index))
			rrb(stack_b);
		redefine_index(tmp, tmp->target);
	}
	pb(stack_a, stack_b);
}

void	ordering(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tmp;

	tmp = ps_soon_bigest(*stack_a, *stack_b);
	if (!tmp)
		return ;
	while (tmp->index != 0)
	{
		if ((tmp->index) <= (ps_size(tmp) - tmp->index))
			ra(stack_a);
		else if ((tmp->index) > (ps_size(tmp) - tmp->index))
			rra(stack_a);
		redefine_index(*stack_a, *stack_b);
	}
	if (ps_size(*stack_b) > 0)
		pa(stack_b, stack_a);
}
