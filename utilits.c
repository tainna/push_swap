/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tainna <tainna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:30:39 by taalmeid          #+#    #+#             */
/*   Updated: 2025/12/22 20:13:17 by tainna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int find_min(t_data *a)
{
    int i;
    int min;

    if (!a || a->size == 0)
        return (0);

    min = a->arr[0];
    i = 1;
    while (i < a->size)
    {
        if (a->arr[i] < min)
            min = a->arr[i];
        i++;
    }
    return (min);
}

int find_max(t_data *a)
{
    int i;
    int max;

    if (!a || a->size == 0)
        return (0);

    max = a->arr[0];
    i = 1;
    while (i < a->size)
    {
        if (a->arr[i] > max)
            max = a->arr[i];
        i++;
    }
    return (max);
}

int find_index(t_data *a, int value)
{
    int i;

    if (!a)
        return (-1);

    i = 0;
    while (i < a->size)
    {
        if (a->arr[i] == value)
            return (i);
        i++;
    }
    return (-1);
}
