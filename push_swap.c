/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:58:13 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/26 16:20:54 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argv, char *argc[])
{
	t_lst		*stack_a;
	t_lst		*stack_b;
	int			*args;

	args = trim(argv, argc);
	if(argv < 3)
	{
		free(args);
		return (0);
	}
	validate_args(argv, args);
	stack_a = NULL;
	stack_b = NULL;
	add_args(&stack_a, args, (argv - 1));
	free(args);
	if(is_sorted(stack_a))
	{
		ps_free_all(stack_a);
		return (0); 
	}
	if (ps_size(stack_a) > 3)
		moviment_stack_b(&stack_a, &stack_b);
	ordering_stack_a(&stack_a, &stack_b);
	ps_free_all(stack_a);
	ps_free_all(stack_b);
	return (0);
}
