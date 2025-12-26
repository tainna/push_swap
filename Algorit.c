/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tainna <tainna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:24:57 by taalmeid          #+#    #+#             */
/*   Updated: 2025/12/26 17:36:51 by tainna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_data *a)
{
    int i;

    i = 0;
    while(i < a->size - 1)
    {
        if(a->arr[i] > a->arr[i + 1])
            return(0);
        i++;
    }
    return(1);
}

void is_two(t_data *a)
{
    sa(a);
}

void is_three(t_data *a)
{
    int x = a->arr[0];
    int y = a->arr[1];
    int z = a->arr[2];

    if (x > y && y < z && x < z)
        sa(a);
    else if (x > y && y > z)
    {
        sa(a);
        rra(a);
    }
    else if (x > y && y < z && x > z)
        ra(a);
    else if (x < y && y > z && x < z)
    {
        sa(a);
        ra(a);
    }
    else if (x < y && y > z && x > z)
        rra(a);
}

void bring_smallest_to_top(t_data *a)
{
    int min_val;
    int min_idx;
    int size;

    min_val = find_min(a);
    min_idx = find_index(a, min_val);
    size = a->size;

    if (min_idx == 0)
        return ;
    
    if (min_idx <= size / 2)
    {
        while (a->arr[0] != min_val)
            ra(a);
    }
    else
    {
        while (a->arr[0] != min_val)
            rra(a);
    }
}


void is_five(t_data *a, t_data *b)
{
    while (a->size > 3)
    {
        bring_smallest_to_top(a);
        pb(a, b);
    }
    is_three(a);
    while (b->size > 0)
        pa(a, b);
}


void algoritm(t_data *a)
{
    t_data *b;

    b = malloc(sizeof(t_data));
    if (!b)
        return;
    b->arr = malloc(sizeof(int) * a->capacity);
    b->size = 0;
    b->capacity = a->capacity;

    if (is_sorted(a))
        return;

    if (a->size == 2)
        is_two(a);
    else if (a->size == 3)
        is_three(a);
    else if (a->size <= 5)
        is_five(a, b);
    else
        sort(a, b);

    free(b->arr);
    free(b);
}