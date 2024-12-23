/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:36:16 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 16:16:09 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	validate_args(int size, int *argc)
{
	if (size == 1)
	{
		write(2, "Error\n", 6);
		free(argc);
		exit(1);
	}
	if (find_duplicate(argc, (size - 1)))
	{
		write(2, "Error\n", 6);
		free(argc);
		exit(1);
	}
}
