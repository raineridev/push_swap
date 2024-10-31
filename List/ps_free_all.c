/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:41:16 by mraineri          #+#    #+#             */
/*   Updated: 2024/10/31 13:09:26 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ps_free_all(ps_lst *list) {
    ps_lst *tmp;
    while (list) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}