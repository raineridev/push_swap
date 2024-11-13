/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_soon_bigest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:59:08 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/12 17:23:33 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"

ps_lst *ps_soon_bigest(ps_lst *stack_a, ps_lst *stack_b) 
{
    ps_lst *cheap_node;
    ps_lst *tmp_a;
    
    if(!stack_a || !stack_b)
        return (NULL);
    tmp_a = stack_a;
    cheap_node = NULL;
    while(tmp_a)
    {
        if(stack_b->num < tmp_a->num) 
        {
            if (!cheap_node) 
                cheap_node = tmp_a;  
            if (cheap_node->num > tmp_a->num) 
                cheap_node = tmp_a;
        }
        tmp_a = tmp_a->next;
    }
    if(!cheap_node)
        return (ps_smallest(stack_a));
    return (cheap_node);
}
