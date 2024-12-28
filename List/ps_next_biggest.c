/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_next_biggest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:59:08 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/28 15:51:45 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*ps_next_biggest(t_lst *stack_a, t_lst *stack_b)
{
	t_lst	*cheap_node;
	t_lst	*tmp_a;

	if (!stack_a || !stack_b)
		return (NULL);
	tmp_a = stack_a;
	cheap_node = NULL;
	while (tmp_a)
	{
		if (stack_b->num < tmp_a->num)
		{
			if (!cheap_node)
				cheap_node = tmp_a;
			if (cheap_node->num > tmp_a->num)
				cheap_node = tmp_a;
		}
		tmp_a = tmp_a->next;
	}
	if (!cheap_node)
		return (ps_smallest(stack_a));
	return (cheap_node);
}
