/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:10:14 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/02 13:26:02 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

ps_lst  *ps_create(int num) 
{
    ps_lst  *lst;
    
    lst = malloc(sizeof(ps_lst));
    if(!lst)
        return (NULL);
        
    lst->num = num;
    lst->next = NULL;
    lst->prev = NULL;

    return (lst);
}

/*
int main(void)
{
    // Create List
    ps_lst *lst_1 = ps_create(11);
    ps_lst *lst_2 = ps_create(12);
    ps_lst *lst_3 = ps_create(13);
    
    if(lst_1->num) 
		printf("\e[42m LIST 1 \e[49m\n");
	else 
		printf("\e[101m LIST 1 \e[49m\n");
    if(lst_2->num) 
		printf("\n\e[42m LIST 2 \e[49m\n");
	else 
		printf("\e[101m LIST 2 \e[49m\n");
    if(lst_3->num) 
		printf("\n\e[42m LIST 3 \e[49m\n");
	else 
		printf("\e[101m LIST 3 \e[49m\n");    
    return (0);
}
*/