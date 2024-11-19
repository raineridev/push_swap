/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_duplicate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:12:21 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/18 03:22:07 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int find_duplicate(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < size - 1) { 
        j = i + 1;  
        while (j < size) { 
            if (arr[i] == arr[j])
                return (1);
            j++; 
        }
        i++;
    }
    return (0);
}