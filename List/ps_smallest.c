/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smallest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:10:06 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/08 23:21:33 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"

ps_lst *ps_smallest(ps_lst *stack)
{
    ps_lst *tmp;
    ps_lst *min_node;

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
    return (min_node); // 
}
