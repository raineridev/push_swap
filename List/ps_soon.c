/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_soon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:59:08 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/13 15:48:42 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"

ps_lst *ps_soon(ps_lst *stack_a, ps_lst *stack_b) 
{
    ps_lst *cheap_node;
    ps_lst *tmp_b;
    
    if(!stack_a || !stack_b)
        return (NULL);
    tmp_b = stack_b;
    cheap_node = NULL;
    while(tmp_b)
    {
        if(stack_a->num > tmp_b->num) 
        {
            if (!cheap_node) 
                cheap_node = tmp_b;  
            if (cheap_node->num < tmp_b->num) 
                cheap_node = tmp_b;
        }
        tmp_b = tmp_b->next;
    }
    if(!cheap_node)
        return (ps_bigest(stack_b));
    return (cheap_node);
}
