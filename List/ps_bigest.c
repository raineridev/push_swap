/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bigest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:10:06 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/31 11:35:36 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"

ps_lst *ps_bigest(ps_lst *stack)
{
    ps_lst *tmp;
    int max_num;
    
    tmp = stack;
    max_num = -2147483648;
    while (tmp)
    {
        if (max_num < tmp->num)
            max_num = tmp->num;
        tmp = tmp->next;
    }
    tmp = stack;
	while(tmp)
	{
		if(max_num == tmp->num)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
