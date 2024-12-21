/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generel_managent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:22:52 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/21 09:08:40 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"


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
    if((tmp_b && tmp_a) && (tmp_a->prev || tmp_b->prev))
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
    
    tmp = more_cheap(*stack_a);
    while (tmp->index != 0)
    {
        if ((tmp->index) <= (ps_size(tmp) - tmp->index) && (tmp->index == tmp->target->index))  
            rr(stack_a, stack_b);
        else if ((tmp->index) <= (ps_size(tmp) - tmp->index))  
            ra(stack_a);
        else if ((tmp->index) > (ps_size(tmp) - tmp->index) && (tmp->index == tmp->target->index))  
            rrr(stack_a, stack_b);
        else if ((tmp->index) > (ps_size(tmp) - tmp->index))
            rra(stack_a);
        redefine_index(tmp, tmp->target);
    }
    while (tmp->target->index != 0)
    {
        if ((tmp->target->index) <= (ps_size(tmp->target) - tmp->target->index))  
            rb(stack_b);
        else if ((tmp->target->index) > (ps_size(tmp->target) - tmp->target->index))
            rrb(stack_b);
        redefine_index(tmp, tmp->target);
    }
    pb(stack_a, stack_b);
}

void ordering(ps_lst **stack_a, ps_lst **stack_b)
{
    ps_lst *tmp;
    
    tmp = ps_soon_bigest(*stack_a, *stack_b);
    if(!tmp)
        return ;
    while (tmp->index != 0)
    {
        if ((tmp->index) <= (ps_size(tmp) - tmp->index))  
            ra(stack_a);
        else if ((tmp->index) > (ps_size(tmp) - tmp->index))
            rra(stack_a);
        redefine_index(tmp, tmp->target);
    }
    if(ps_size(*stack_b) > 0)
        pa(stack_b, stack_a);
}

int main(int argv, char *argc[])
{
    int *args = trim(argv, argc);
    validate_args(argv, args);
    ps_lst *stack_a = NULL;
    ps_lst *stack_b = NULL;
    add_args(&stack_a, args,(argv - 1));
    free(args);
    if(ps_size(stack_a) > 3)
        moviment_stack_b(&stack_a, &stack_b);
    ordering_stack_a(&stack_a, &stack_b);
    ps_free_all(stack_a);
    ps_free_all(stack_b);
    return (0);
}

