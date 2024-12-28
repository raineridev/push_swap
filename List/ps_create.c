/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:10:14 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 16:28:50 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*ps_create(int num)
{
	t_lst	*lst;

	lst = malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	lst->num = num;
	lst->cost = 0;
	lst->total_cost = 0;
	lst->target = NULL;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}
