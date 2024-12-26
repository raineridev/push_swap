/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_target.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:11:52 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 18:14:30 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_target(t_lst *stack_a, t_lst *stack_b)
{
	t_lst	*tmp_a;

	if (!stack_a || !stack_b)
		return ;
	tmp_a = stack_a;
	while (tmp_a)
	{
		tmp_a->target = ps_soon(tmp_a, stack_b);
		tmp_a = tmp_a->next;
	}
}
