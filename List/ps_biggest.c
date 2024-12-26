/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_biggest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:10:06 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 16:28:50 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*ps_biggest(t_lst *stack)
{
	t_lst	*tmp;
	int		max_num;

	tmp = stack;
	max_num = -2147483648;
	while (tmp)
	{
		if (max_num < tmp->num)
			max_num = tmp->num;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp)
	{
		if (max_num == tmp->num)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
