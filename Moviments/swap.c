#include "../push_swap.h"

void	sa(ps_lst **stack_a)
{
	if(!stack_a)
		return ;


}


int main(void)
{
	ps_lst *stack_a;
	ps_lst *stack_b;

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
	// Check Nodes
	if(stack_a_1->next->next && stack_a_1->num && stack_a_2->num && stack_a_3->num) 
		printf("\e[42m STACK A \e[49m\n");
	else 
		printf("\e[101m STACK A \e[49m\n");
	
	return (0);
}