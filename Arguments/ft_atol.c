/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:02:27 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/28 17:40:08 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long int	ft_atol(char *str)
{
	long int	num;
	int			i;
	int			signal;

	i = 0;
	num = 0;
	if (!str || !*str)
		return (0);
	if (ft_strlen(str) > 12)
		return 999999999999;
	signal = (str[i] != '-') - (str[i] == '-');
	i += (str[i] == '-' || str[i] == '+');
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * signal);
}
