/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_managent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:22:52 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/07 09:32:32 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"

void	ps_target(ps_lst *stack_a, ps_lst *stack_b)
{
    ps_lst  *tmp_a;
    ps_lst  *tmp_b;
    
    if (!stack_a || !stack_b)
        return;
    tmp_a = stack_a;
    tmp_b = stack_b;
    while(tmp_b && tmp_a)
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
        {
            printf("HEY");
            cheap_node = tmp;
        }
        tmp = tmp->next;
    }
    return (cheap_node);
}

void make_moviment(ps_lst **stack, ps_lst **stack_b, int index)
{
    ps_lst *tmp;

    tmp = *stack;
    printf("%d[%d],", tmp->num, index);
    while(tmp && tmp->index != index)
        tmp = tmp->next;
    printf("%d\n", tmp->num);
    while (tmp->index != 0)
    {
        if (tmp->index == 1)
            sa(stack); 
        else if ((tmp->index - 1) <= (ps_size(*stack) - tmp->index))  
            ra(stack);
        else if ((tmp->index - 1) > (ps_size(*stack) - tmp->index))
            rra(stack);
        redefine_index(*stack, *stack_b);
    }
    pb(stack, stack_b);
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
     int args[] = {9,5,7,99,6,8,1,47,17,11};
    //  int args[] = {99,98,45,50,23,2,8};
     int size = sizeof(args) / sizeof(args[0]);
     printf("Size of Args:%lu, Size of Num:%lu: Result:%lu\n", sizeof(args), sizeof(args[0]),sizeof(args) / sizeof(args[0]));
    ps_lst *stack_a = NULL;
    ps_lst *stack_b = NULL;
    add_args(&stack_a, args, size);
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    if(stack_b->num != ps_bigest(stack_b)->num)
        sa(&stack_b);
    redefine_index(stack_a, stack_b);
    ps_target(stack_a, stack_b);
    cost_stack(stack_a);
    cost_stack(stack_b);
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
    
    printf("%d\n", more_cheap(stack_a)->num);
    ps_free_all(stack_a);
    ps_free_all(stack_b);
    return (0);
}

