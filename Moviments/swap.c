/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:59:28 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/01 12:59:30 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(ps_lst **stack_a)
{
	if(!stack_a || !(*stack_a)->next)
		return ;
	
	ps_lst *tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	write(1, "sa\n", 3);
}

void	sb(ps_lst **stack_b)
{
	if(!stack_b || !(*stack_b)->next)
		return ;
	
	ps_lst *tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;

	write(1, "sb\n", 3);
}

void	ss(ps_lst **stack_a, ps_lst **stack_b)
{
	if(!stack_a || !(*stack_a)->next || !stack_b || !(*stack_b)->next)
		return ;

	ps_lst *tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;

	write(1, "ss\n", 3);
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
		printf("\e[42m STACK A \e[49m\n");
	else 
		printf("\e[101m STACK A \e[49m\n");
	// Stack A Data(Copy the position for us to check)
	int stack_a_data_1 = stack_a_1->num;
	int stack_a_data_2 = stack_a_2->num;
	sa(&stack_a_1);
	// Tests
	printf("\nValue Stack A(P1):%d, (P2): %d\n", stack_a_1->num, stack_a_1->next->num);
	if(stack_a_data_1 == stack_a_1->next->num && stack_a_data_2 == stack_a_1->num) 
		printf("\n\e[42m EXCHANGE SUCCESSFULLY COMPLETED A \e[49m\n");
	else
		printf("\e[101m FAULTY EXCHANGE \e[49m\n");
	// Stack B Data(Copy the position for us to check)
	int stack_b_data_1 = stack_b_1->num;
	int stack_b_data_2 = stack_b_2->num;
	sb(&stack_b_1);
	// Tests
	printf("\nValue Stack B(P1):%d, (P2): %d\n", stack_b_1->num, stack_b_1->next->num);
	if(stack_b_data_1 == stack_b_1->next->num && stack_b_data_2 == stack_b_1->num) 
		printf("\n\e[42m EXCHANGE SUCCESSFULLY COMPLETED B \e[49m\n");
	else
		printf("\e[101m FAULTY EXCHANGE \e[49m\n");
	ss(&stack_a_1, &stack_b_1);
	printf("\nValue Stack A(P1):%d, (P2): %d | Value Stack B(P1):%d, (P2): %d\n ", stack_a_1->num, stack_a_1->next->num, stack_b_1->num, stack_b_1->next->num);
	if(stack_b_data_1 == stack_b_1->num && stack_b_data_2 == stack_b_1->next->num && (stack_a_data_1 == stack_a_1->num && stack_a_data_2 == stack_a_1->next->num)) 
		printf("\n\e[42m EXCHANGE SUCCESSFULLY COMPLETED B \e[49m\n");
	else
		printf("\n\e[101m FAULTY EXCHANGE \e[49m\n");
	return (0);
}
*/