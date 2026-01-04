/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utilits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:26:10 by taalmeid          #+#    #+#             */
/*   Updated: 2026/01/04 16:35:14 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

int	find_target_pos(t_data *a, int value)
{
	int	i;

	i = 0;
	if (value < find_min(a) || value > find_max(a))
		return (find_index(a, find_min(a)));
	while (i < a->size)
	{
		if (i == 0)
		{
			if (a->arr[i] > value && a->arr[a->size - 1] < value)
				return (i);
		}
		else if (a->arr[i] > value && a->arr[i - 1] < value)
			return (i);
		i++;
	}
	return (0);
}

static void	do_double_rotate(t_data *a, t_data *b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	execute_move(t_data *a, t_data *b, int cost_a, int cost_b)
{
	do_double_rotate(a, b, &cost_a, &cost_b);
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
	pa(a, b);
}
