/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:09:50 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/26 16:15:42 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int is_sorted(t_lst *stack)
{
	int stack_size;
	int i;

	i = 0;
	stack_size = ps_size(stack);
	while(stack)
	{
        if (stack->next && stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
