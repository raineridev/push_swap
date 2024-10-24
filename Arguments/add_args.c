/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:23:33 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/07 15:04:41 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void add_args(ps_lst **head, int *args)
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
        ps_link(head ,&node, i);
    }
}

int main(void)
{
    int args[] = {1,7,4,2,3,8,9,10}; 
    ps_lst *head = malloc(sizeof(ps_lst));
    add_args(&head, args);
    int i = 0;
    while (head->next)
    {
        printf("%d -? [%d] ->%d\n", i, head->index, head->num);
        i++;
        head = head->next;
    }
    return (0);
}

