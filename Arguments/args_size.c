/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:03:04 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/14 00:04:51 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int args_size(char *argc[])
{
    int	i;

	i = 0;
	if(!argc)
		return (-1);
	while(argc[i])
		i++;
	return (--i);
}