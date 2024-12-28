/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smallest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:10:06 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 16:35:51 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*ps_smallest(t_lst *stack)
{
	t_lst	*tmp;
	t_lst	*min_node;

	if (!stack)
		return (NULL);
	tmp = stack;
	min_node = stack;
	while (tmp)
	{
		if (tmp->num < min_node->num)
			min_node = tmp;
		tmp = tmp->next;
	}
	return (min_node);
}
