/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:55:10 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/14 01:17:50 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int *trim(int argv,char *argc[])
{
    int i;
    int *list;
    
    i = 1;
    list = malloc(argv * sizeof(int));
    if(!list)
        return (NULL);
    while(argc[i])
    {
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
