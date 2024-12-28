/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:23:33 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 16:28:50 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_args(t_lst **head, int *args, int size)
{
	t_lst	*node;
	int		i;

	i = 0;
	if (!args)
		return ;
	*head = ps_create(args[i]);
	while (++i < size)
	{
		node = ps_create(args[i]);
		ps_link(head, &node, i);
	}
}
