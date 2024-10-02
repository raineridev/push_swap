/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:27:55 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/01 21:07:04 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(ps_lst **stack)
{
    ps_lst  *tmp;
    ps_lst  *tmp_run;
    
    if (!*stack || !(*stack)->next)
        return ;
    tmp = *stack;
    tmp_run = *stack;

    while(tmp_run->next)
        tmp_run = tmp_run->next;
    tmp_run->prev->next = NULL;
    tmp_run->next = tmp;
    *stack = tmp_run;
    
    (*stack)->prev = NULL;
    tmp->prev = *stack;
}

void    ra(ps_lst **stack)
{
    rotate(stack);
    write(1, "ra\n", 3);
}

void    rb(ps_lst **stack)
{
    rotate(stack);
    write(1, "ra\n", 3);
}

void    rr(ps_lst **stack_a, ps_lst **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
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
    ra(&stack_a_1);
    printf("%d, %d, %d", stack_a_1->num, stack_a_1->next->num, stack_a_1->next->next->num);
    return (0);
}
*/