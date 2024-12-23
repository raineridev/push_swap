/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:58:13 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 16:28:50 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argv, char *argc[])
{
	int *args = trim(argv, argc);
	if (argv  < 3)
	{
		write(2, "Error\n", 6);
		free(args);
		exit(1);
	}
	validate_args(argv, args);
	t_lst	*stack_a = NULL;
	t_lst	*stack_b = NULL;
	add_args(&stack_a, args,(argv - 1));
	free(args);
	if (ps_size(stack_a) > 3)
		moviment_stack_b(&stack_a, &stack_b);
	ordering_stack_a(&stack_a, &stack_b);
	ps_free_all(stack_a);
	ps_free_all(stack_b);
	return (0);
}
