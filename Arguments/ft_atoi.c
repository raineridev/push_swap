/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:02:27 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/06 20:30:02 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi( char *str)
{
	int	i;
	int	num;
	int	signal;

	i = 0;
	num = 0;
	if (!str || !*str)
		return (0);
	signal = (str[i] != '-') - (str[i] == '-');
	i += (str[i] == '-' || str[i] == '+');
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * signal);
}