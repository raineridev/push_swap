/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:41:30 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/17 19:41:19 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void reverse_rotate(ps_lst **stack)
{
    ps_lst *tmp;
    ps_lst *tmp_run;

    tmp = *stack;
    tmp_run = *stack;
    while(tmp->next)
        tmp = tmp->next;
    tmp->prev->next = NULL;
    tmp_run->prev = tmp;
    *stack = tmp;
    (*stack)->next = tmp_run;
    (*stack)->prev = NULL;
}

void    rra(ps_lst **stack_a)
{
    reverse_rotate(stack_a);
    write(1, "rra\n", 4);
}

void    rrb(ps_lst **stack_a)
{
    reverse_rotate(stack_a);
    write(1, "rrb\n", 4);
}

void    rrr(ps_lst **stack_a, ps_lst **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    write(1, "rrr\n", 4);
}

/*
int main(void)
{
    // Create Stack
    ps_lst *stack_a_1 = malloc(sizeof(ps_lst));
    ps_lst *stack_a_2 = malloc(sizeof(ps_lst));
    ps_lst *stack_a_3 = malloc(sizeof(ps_lst));
    // Connect Next Node
    stack_a_1->next = stack_a_2;
    stack_a_2->next = stack_a_3;
    stack_a_3->next = NULL;
    // Connect Next Node
    stack_a_1->prev = NULL;
    stack_a_2->prev = stack_a_1;
    stack_a_3->prev = stack_a_2;
    // Seeding Stack A
	stack_a_1->num = 11;
	stack_a_2->num = 12;
	stack_a_3->num = 13;
    // Check Nodes
	if(stack_a_1->next->next && stack_a_1->num && stack_a_2->num && stack_a_3->num) 
		printf("\e[42m STACK A \e[49m\n");
	else 
		printf("\e[101m STACK A \e[49m\n");
    reverse_rotate(&stack_a_1);
    while(stack_a_1)
    {
        printf("%d\n", stack_a_1->num);
        stack_a_1 = stack_a_1->next;
    }
    return (0);
}
*/