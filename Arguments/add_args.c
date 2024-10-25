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

