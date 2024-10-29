/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_managent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:22:52 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/29 12:32:17 by mraineri         ###   ########.fr       */
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
        	printf("[%d]%d(%d)", tmp_a->index, tmp_a->num, tmp_b->num);
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
    //int args[] = {400,101,3,9,405,402,-35,45,99,23,2,8,56,130,300,301,302};
    ps_lst *stack_a = malloc(sizeof(ps_lst));
    ps_lst *stack_b = malloc(sizeof(ps_lst));
	stack_a = NULL;
    stack_b = NULL;
    int arr[110] = {
    954, 702, 112, 831, 456, 210, 568, 128, 703,  84, 
    497, 233, 673, 159, 302, 812, 473, 298, 715,  69, 
    623, 384, 789, 256, 348, 145, 529, 618, 415, 901, 
    52,  746, 503, 332, 671, 281, 469,  92, 811, 385, 
    126, 599, 211, 777, 322, 988, 548, 207, 140, 614, 238, 
    341, 778, 583, 625, 401, 754, 287, 110, 499, 219, 
    362, 713, 623, 308, 501, 279, 641, 170, 567, 219, 
    743, 500, 143, 811, 392, 726, 553,  73, 194, 675, 
    345, 240, 426, 649, 522, 300, 184, 719, 128, 759, 
    432, 591, 209, 863,  90, 310, 642, 234, 159, 804,
    345, 495, 999, 666,333,444
};
    add_args(&stack_a, arr);
    //pb(&stack_a, &stack_b);
    //pb(&stack_a, &stack_b);
    ps_bigest(stack_a);
    //ps_target(stack_a, stack_b);
    //redefine_index(stack_a, stack_b);
    //cost_stack(stack_a);
    //cost_stack(stack_b);
    
    // 3 Fun
    return (0);
}
