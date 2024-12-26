/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:59:08 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/26 16:17:40 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*ps_next(t_lst *stack_a, t_lst *stack_b)
{
	t_lst	*cheap_node;
	t_lst	*tmp_b;

	if (!stack_a || !stack_b)
		return (NULL);
	tmp_b = stack_b;
	cheap_node = NULL;
	while (tmp_b)
	{
		if (stack_a->num > tmp_b->num)
		{
			if (!cheap_node)
				cheap_node = tmp_b;
			if (cheap_node->num < tmp_b->num)
				cheap_node = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	if (!cheap_node)
		return (ps_biggest(stack_b));
	return (cheap_node);
}
