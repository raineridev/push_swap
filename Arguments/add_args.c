/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:23:33 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/31 13:16:13 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void add_args(ps_lst **head, int *args, int size)
{
    ps_lst *node;
    int i = 0;

    if (!args || !args[i])
        return;

    *head = ps_create(args[i]);
    
    while (i <= size)
    {
        node = ps_create(args[i++]);
        ps_link(head, &node, i);
    }
}


