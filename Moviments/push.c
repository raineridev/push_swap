/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:59:21 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/31 11:44:28 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    push(ps_lst **stack_a, ps_lst **stack_b)
{    
	ps_lst *tmp;
	ps_lst *tmp_a;

	tmp = *stack_b;
	tmp_a = (*stack_a)->next;
	
	*stack_b = *stack_a;
	(*stack_b)->next = tmp;
	*stack_a = tmp_a;
    if((*stack_b)->next)
		(*stack_b)->next->prev = *stack_b;
    tmp = *stack_b;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = NULL;
}

void	pb(ps_lst **stack_a, ps_lst **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}


void	pa(ps_lst **stack_b, ps_lst **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

/*
int main(void)
{
    // Stack A
	ps_lst *stack_a_1 = malloc(sizeof(ps_lst));
	ps_lst *stack_a_2 = malloc(sizeof(ps_lst));
	ps_lst *stack_a_3 = malloc(sizeof(ps_lst));
	// Stack B
	ps_lst *stack_b_1 = malloc(sizeof(ps_lst));
	ps_lst *stack_b_2 = malloc(sizeof(ps_lst));
	ps_lst *stack_b_3 = malloc(sizeof(ps_lst));
	// Seeding Stack A
	stack_a_1->num = 11;
	stack_a_2->num = 12;
	stack_a_3->num = 13;
	// Seeding Stack B
	stack_b_1->num = 21;
	stack_b_2->num = 22;
	stack_b_3->num = 23;
	// Connecting the nodes Stack A
	stack_a_1->next = stack_a_2;
	stack_a_2->next = stack_a_3;
	stack_a_3->next = NULL;
	// Connecting the nodes Stack A
	stack_b_1->next = stack_b_2;
	stack_b_2->next = stack_b_3;
	stack_b_3->next = NULL;
	// Check Nodes
	if(stack_a_1->next->next && stack_a_1->num && stack_a_2->num && stack_a_3->num) 
		printf("\n\e[42m STACK A \e[49m\n");
	else 
		printf("\e[101m STACK A \e[49m\n");
    if(stack_b_1->next->next && stack_b_1->num && stack_b_2->num && stack_b_3->num) 
		printf("\e[42m STACK B \e[49m\n");
	else 
		printf("\e[101m STACK B \e[49m\n");

	// Data Stack A
	int stack_a_data_1  = stack_a_1->num; 
	int stack_a_data_2  = stack_a_2->num;
	int stack_a_data_3  = stack_a_3->num; 
	// Data Stack B
	int stack_b_data_1  = stack_b_1->num; 
	int stack_b_data_2  = stack_b_2->num;
	int stack_b_data_3  = stack_b_3->num; 
	pa(&stack_a_1, &stack_b_1);
	printf("\nValue Stack A(P1):%d, (P2): %d | Value Stack B(P1):%d, (P2): %d, (P3): %d (P4): %d", stack_a_1->num, stack_a_1->next->num, stack_b_1->num, stack_b_1->next->num, stack_b_1->next->next->num,  stack_b_1->next->next->next->num);
	if((stack_a_data_2 == stack_a_1->num && stack_a_data_3 == stack_a_1->next->num)
	 && 
	(stack_a_data_1 == stack_b_1->num && stack_b_data_1 == stack_b_1->next->num && stack_b_data_2 == stack_b_1->next->next->num && stack_b_data_3 == stack_b_1->next->next->next->num)) 
		printf("\n\e[42m EXCHANGE SUCCESSFULLY COMPLETED A -> B \e[49m\n");
	else
		printf("\n\e[101m FAULTY EXCHANGE \e[49m\n");
	printf("\n\nPrev (P2) -> %d\n\n", stack_b_1->next->prev->num);
	return (0);
}
*/
