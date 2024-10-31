/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:14:51 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/28 16:52:34 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ps_size(ps_lst *stack)
{
	int	i;
	
	if(!stack)
		return (-1);
	i = 0;
    while(stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (++i);
}