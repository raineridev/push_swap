/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:55:10 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/26 16:49:36 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	validate_str(const char *str)
{
	if (*str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	validate_int(long int nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (1);
	return (0);
}

int	*trim(int argv, char *argc[])
{
	int	i;
	int	*list;
	i = 1;
	
	list = malloc((argv - 1) * sizeof(int));
	if (!list)
		return (NULL);
	while (i < argv)
	{
		if (validate_str(argc[i]) || validate_int(ft_atol(argc[i])) || !argc[i][0])
		{
			write(2, "Error\n", 6);
			free(list);
			exit(1);
		}
		list[i - 1] = ft_atol(argc[i]);
		i++;
	}
	return (list);
}
