/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:26:54 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/02 13:44:26 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ps_link(ps_lst **lst, ps_lst **node, int index)
{
    if(!(*lst) && !(*node))
        return ;
    
    ps_lst *tmp;
    
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = *node;
    (*node)->index = index;
    (*node)->prev = *lst;
}  
/*
int main(void)
{
    // Create List
    ps_lst *lst_1 = ps_create(11);
    ps_lst *lst_2 = ps_create(12);
    ps_lst *lst_3 = ps_create(13);
    // Tests
    if(lst_1->num) 
		printf("\n\e[42m LIST 1 \e[49m\n");
	else 
		printf("\n\e[101m LIST 1 \e[49m\n");
    if(lst_2->num) 
		printf("\n\e[42m LIST 2 \e[49m\n");
	else 
		printf("\e[101m LIST 2 \e[49m\n");
    if(lst_3->num) 
		printf("\n\e[42m LIST 3 \e[49m\n");
	else 
		printf("\e[101m LIST 3 \e[49m\n");    
    // Link Nodes
    ps_link(&lst_1, &lst_2);
    ps_link(&lst_1, &lst_3);
    // Connection Tests
        if(lst_1->next && lst_2->prev) 
		printf("\n\e[42m CONNECTION 1 \e[49m\n");
	else 
		printf("\n\e[101m CONNECTION 1 \e[49m\n");
    if(lst_2->next && lst_3->prev) 
		printf("\n\e[42m CONNECTION 2 \e[49m\n\n");
	else 
		printf("\n\e[101m CONNECTION 2 \e[49m\n\n");
    return (0);
}
*/
