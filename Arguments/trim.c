/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:55:10 by mraineri          #+#    #+#             */
/*   Updated: 2024/12/23 15:37:18 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	validate_str(const char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
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
		if (validate_str(argc[i]))
		{
			write(2, "Error\n", 6);
			free(list);
			exit(1);
		}
		list[i - 1] = ft_atoi(argc[i]);
		i++;
	}
	return (list);
}
