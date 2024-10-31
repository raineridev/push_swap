/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_managent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:22:52 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/31 13:38:00 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"

void	ps_target(ps_lst *stack_a, ps_lst *stack_b)
{
    if (!stack_a || !stack_b)
        return;
    ps_lst  *tmp_a;
    ps_lst  *tmp_b;
    
    tmp_a = stack_a;
    tmp_b = stack_b;
    while(tmp_b->next && tmp_a->next)
    {
        if (tmp_a->num < tmp_b->num)
            tmp_a->target = ps_bigest(stack_b);
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
	int i;

    tmp_a = stack_a;
    tmp_b = stack_b;
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

void cost_stack(ps_lst *stack)
{
    ps_lst  *tmp;
    
    if(!stack)
        return ;
    tmp = stack;
    while(tmp)
    {
        if(tmp->index == 0)
            tmp->cost = 0;
        else if(tmp->index == 1)
            tmp->cost = tmp->index;
        else if((tmp->index - 1) <= (ps_size(tmp) - tmp->index))
            tmp->cost = tmp->index;
        else if((tmp->index - 1) > (ps_size(tmp) - tmp->index))
            tmp->cost = ps_size(stack) - tmp->index;
        tmp = tmp->next;
    }
}

//void more_cheap(ps_lst *stack_a, ps_lst *stack)
//{   
//    ps_lst  *tmp_a;
//    ps_lst  *tmp_b;

//    tmp_a = stack_a;
//    tmp_b = stack_b;
//    while(tmp_a)
//    {
//        printf(" %d", );
//    }
//}

int main(void)
{
     int args[] = {9,2,45,99,23,1,8,47,10,45};
     int size = sizeof(args) / sizeof(args[0]);
     printf("Size of Args:%lu, Size of Num:%lu: Result:%lu\n", sizeof(args), sizeof(args[0]),sizeof(args) / sizeof(args[0]));
    //int args[] = {99,98,45,50,23,2,8};
    ps_lst *stack_a = NULL;
    ps_lst *stack_b = NULL;
    add_args(&stack_a, args, size);
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    ps_target(stack_a, stack_b);
    redefine_index(stack_a, stack_b);
    ps_lst *tmp = stack_a;
    while(tmp->next)
    {
        printf("Node -> [%d]%d\n", tmp->index, tmp->num); 
        tmp = tmp->next;
    }
    ps_free_all(stack_a);
    ps_free_all(stack_b);
    return (0);
}
