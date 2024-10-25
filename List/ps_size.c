/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:14:51 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/24 21:22:15 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ps_size(ps_lst *stack)
{
    int	i;
    if(!stack)
        return (-1);
	i = 1;
    while(stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}