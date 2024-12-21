/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:55:10 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/21 18:41:21 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	validate_str(char *str)
{
	while(*str)
	{
		if((*str >= 32 && *str <= 47) || (*str >= 58 && *str <= 126))
            return (1);
		str++;
	}
    return (0);
}

int *trim(int argv,char *argc[])
{
    int i;
    int *list;
    
    i = 1;
    list = malloc((argv - 1) * sizeof(int));
    if(!list)
        return (NULL);
    while(i < argv)
    {
        if(validate_str(argc[i]))
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

// int main(int argv, char *argc[])
// {
//     int *i = (trim(argv, argc));
//     int b = 0;
//     while(b < (argv - 1))
//         printf("%d\n",i[b++]);
    
//     return (0);
// }
