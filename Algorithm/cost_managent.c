/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_managent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:22:52 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/11 15:58:50 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"

void logText(ps_lst *stack_a, ps_lst *stack_b) 
{
    ps_lst *tmp = stack_a;
    printf("===================\n");
    printf("\e[44m NODES(STACK A) WITH INDEX \e[49m\n");
    while(tmp)
    {
        printf("Node -> [%d]%d\n", tmp->index, tmp->num); 
        tmp = tmp->next;
    }
    tmp = stack_b;
    printf("===================\n");
    printf("\e[44m NODES(STACK B) WITH INDEX \e[49m\n");
    while(tmp)
    {
        printf("Node -> [%d]%d\n", tmp->index, tmp->num); 
        tmp = tmp->next;
    }
    printf("===================\n");
    printf("\e[42m TARGET NODES \e[49m\n");
    tmp = stack_a;
    while(tmp)
    {
        printf("Node -> [%d]%d  -? [%d]%d\n", tmp->index, tmp->num, tmp->target->index, tmp->target->num); 
        tmp = tmp->next;
    }
    printf("===================\n");
    printf("\e[43m COST NODES(STACK A) \e[49m\n");
    tmp = stack_a;
    while(tmp)
    {
        printf("Node -> [%d]%d | Cost -> %d\n", tmp->index, tmp->num, tmp->cost); 
        tmp = tmp->next;
    }
    printf("===================\n");
    printf("\e[43m COST NODES(STACK B) \e[49m\n");
    tmp = stack_b;
    while(tmp)
    {
        printf("Node -> [%d]%d | Cost -> %d\n", tmp->index, tmp->num, tmp->cost); 
        tmp = tmp->next;
    }
    printf("===================\n");
    printf("\e[45m COST NODES TOTAL COST(STACK A) \e[49m\n");
    tmp = stack_a;
    while(tmp)
    {
        printf("Node -> [%d]%d -. [%d]%d  Total Cost -> %d\n", tmp->index, tmp->num,tmp->target->index, tmp->target->num, (tmp->cost + tmp->target->cost)); 
        tmp = tmp->next;
    }
}

void	ps_target(ps_lst *stack_a, ps_lst *stack_b)
{
    ps_lst  *tmp_a;
    
    if (!stack_a || !stack_b)
        return;
    tmp_a = stack_a;
    while(tmp_a)
    {
        tmp_a->target = ps_soon(tmp_a, stack_b);
        tmp_a = tmp_a->next;
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
    if(tmp_a->prev || tmp_b->prev)
    {
        while(tmp_a->prev)
            tmp_a = tmp_a->prev;
        while(tmp_b->prev)
            tmp_b = tmp_b->prev;
    }
	while(tmp_a)
	{
		tmp_a->index = i++;
		tmp_a = tmp_a->next;
	}
	i = 0;
	while(tmp_b)
	{
		tmp_b->index = i++;
		tmp_b = tmp_b->next;
	}
}

void cost_stack(ps_lst *stack)
{
    ps_lst  *tmp;
    
    if (!stack)
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

ps_lst *more_cheap(ps_lst *stack)
{
    ps_lst *cheap_node;
    ps_lst *tmp;
    
    if(!stack)
        return (NULL);
    tmp = stack;
    cheap_node = stack;
    while(tmp)
    {
        if((tmp->cost + tmp->target->cost) < (cheap_node->cost + cheap_node->target->cost))
            cheap_node = tmp;
        tmp = tmp->next;
    }
    return (cheap_node);
}

void make_moviment(ps_lst **stack_a, ps_lst **stack_b)
{
    ps_lst *tmp;
    
    redefine_index(*stack_a, *stack_b);
    tmp = more_cheap(*stack_a);
    while (tmp->index != 0)
    {
        if(tmp->target->index == 594593)
            printf("1");
        // if (tmp->index == 1)
        //     sa(stack_a); 
        else if ((tmp->index - 1) <= (ps_size(tmp) - tmp->index))  
            ra(stack_a);
        else if ((tmp->index - 1) > (ps_size(tmp) - tmp->index))
            rra(stack_a);
        redefine_index(tmp, tmp->target);
    }
    while(tmp->target->index != 0)
    {
        if(tmp->target->index == 594593)
            printf("1");
        // if (tmp->target->index == 1)
        //     sb(stack_b); 
        else if ((tmp->target->index - 1) <= (ps_size(tmp->target) - tmp->target->index))  
            rb(stack_b);
        else if ((tmp->target->index - 1) > (ps_size(tmp->target) - tmp->target->index))
            rrb(stack_b);
        redefine_index(tmp, tmp->target);
    }
    *stack_a = tmp;
    *stack_b = tmp->target;
    pb(stack_a, stack_b);
    cost_stack(*stack_a);
    cost_stack(*stack_b);
    ps_target(*stack_a, *stack_b);
}


// int main(void)
// {
//     int args[] = {9,5,7,99,8,1,8,47,17,11};
//     int size = sizeof(args) / sizeof(args[0]);
//     ps_lst *stack_a = NULL;
//     ps_lst *stack_b = NULL;
//     add_args(&stack_a, args, size);
//     pb(&stack_a, &stack_b);
//     pb(&stack_a, &stack_b);
//     pb(&stack_a, &stack_b);
//     printf("%d\n",ps_soon(stack_a->next, stack_b)->num);
//     ps_target(stack_a, stack_b);
//     more_cheap(stack_a);
//     return (0);
// }

int main(void)
{
    //  int args[] = {99,98,45,50,23,2,8};
    // int args[] = {9,1,45,99,23,2,8,47,10,11};
    int args[] = {60,77,1,37,44,79,20,33,57,54,13,42,39,41,6,86,31,21,3,7,97,49,59,50,90,23,88,51,76,81,82,26,22,69,67,56,24,27,18,5,28,2,40,53,75,65,38,92,91,58,84,12,100,74,48,4,34,46,32,43,9,36,73,83,64,66,30,96,85,14,80,78,94,17,63,19,35,93,55,70,47,16,52,71,15,89,62,29,87,8,45,98,11,25,99,10,95,68,72,61};
    // int args[] = {99,0,25,-38,10,7,42};
    int size = sizeof(args) / sizeof(args[0]);
    // printf("Size of Args:%lu, Size of Num:%lu: Result:%lu\n", sizeof(args), sizeof(args[0]),sizeof(args) / sizeof(args[0]));
    ps_lst *stack_a = NULL;
    ps_lst *stack_b = NULL;
    add_args(&stack_a, args, size);
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    if(stack_b->num != ps_bigest(stack_b)->num)
        sa(&stack_b);
    redefine_index(stack_a, stack_b);
    ps_target(stack_a, stack_b);
    cost_stack(stack_a);
    cost_stack(stack_b);
    while(ps_size(stack_a) != 3)
    {
    make_moviment(&stack_a, &stack_b);
    redefine_index(stack_a, stack_b);
    cost_stack(stack_a);
    cost_stack(stack_b);
    ps_target(stack_a, stack_b);
    }
    while((ps_bigest(stack_b)->index != 0))
    {
        rb(&stack_b);
        redefine_index(stack_a, stack_b);
    }
    sa(stack_a);
    rra(stack_a);
    logText(stack_a, stack_b);
    ps_free_all(stack_a);
    ps_free_all(stack_b);
    return (0);
}

