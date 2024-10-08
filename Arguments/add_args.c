/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:29:17 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/08 16:57:03 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	add_args(ps_lst **head, int *args)
{
    ps_lst *node;
    int i;
    if(!args)
        return ;
    i = 0;
    *head = ps_create(args[i]);
    while(args[i++])
    {
        node = ps_create(args[i]);
        ps_link(head ,&node);
    }

    return (i);
}

/*
int main(void)
{
    int args[] = {9,1,7,4,10,2,3,8}; 
    ps_lst *head = malloc(sizeof(ps_lst));
    add_args(&head, args);
    int i = 0;
    while (head->next)
    {
        printf("[%d] ->%d\n", i, head->num);
        i++;
        head = head->next;
    }
    
    return (0);
}
*/