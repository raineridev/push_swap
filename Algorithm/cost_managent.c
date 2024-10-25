/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_managent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:22:52 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/25 18:34:17 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"

void	ps_target(ps_lst *stack_a, ps_lst *stack_b)
{
    ps_lst  *tmp_a;
    ps_lst  *tmp_b;

    tmp_a = stack_a;
    tmp_b = stack_b;
    
    while(tmp_b->next && tmp_a->next)
    {
        if (tmp_a->num < tmp_b->num)
        	tmp_b = tmp_b->next;
        if (!tmp_a->target)
            tmp_a->target = tmp_b;
        tmp_b = tmp_b->next;
        if (tmp_a->target->num < tmp_b->num && tmp_a->num > tmp_b->num)
            tmp_a->target = tmp_b;
        if (!tmp_b->next)
        {
            tmp_a = tmp_a->next;
            tmp_b = stack_b;
        }
    }
}

void redefine_index(ps_lst *stack_a, ps_lst *stack_b)
{
    ps_lst  *tmp_a;
    ps_lst  *tmp_b;

    tmp_a = stack_a;
    tmp_b = stack_b;
	
	int i;

	i = 0;
	while(tmp_a->next)
	{
		tmp_a->index = i++;
		tmp_a = tmp_a->next;
	}
	tmp_a->index = i;
	i = 0;
	while(tmp_b->next)
	{
		tmp_b->index = i++;
		tmp_b = tmp_b->next;
	}
	tmp_b->index = i;
}

/*
int main(void)
{
    int args[] = {9,1,45,99,23,2,8,47};
    ps_lst *stack_a = malloc(sizeof(ps_lst));
    ps_lst *stack_b = malloc(sizeof(ps_lst));
	stack_a = NULL;
    stack_b = NULL;
    add_args(&stack_a, args);
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    ps_target(stack_a, stack_b);

	ps_lst *tmp = stack_a;
	while(tmp->next)
	{
		printf("Node -> Index[%d] -. Value [%d] -? Target Num [%d] -? Target Index [%d]\n", tmp->index, tmp->num, tmp->target->num, tmp->target->index); 
		tmp = tmp->next;
	}
	redefine_index(stack_a, stack_b);
	tmp = stack_a;
	printf("\n\n");
	while(tmp->next)
	{
		printf("Node -> Index[%d] -. Value [%d] -? Target Num [%d] -? Target Index [%d]\n", tmp->index, tmp->num, tmp->target->num, tmp->target->index); 
		tmp = tmp->next;
	}
    return (0);
}
*/