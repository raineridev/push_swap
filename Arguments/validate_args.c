/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:36:16 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/21 15:40:33 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    validate_args(int size, int *argc)
{
    if(size == 1)
    {
        write(2, "Error\n", 6);
        free(argc);
        exit(1);
    }
    
    if(find_duplicate(argc, (size - 1)))
    {
        write(2, "Error\n", 6);
        free(argc);
        exit(1);
    }
}
