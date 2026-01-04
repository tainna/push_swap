/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:25:26 by taalmeid          #+#    #+#             */
/*   Updated: 2026/01/04 17:05:27 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	turkey(t_data *a, t_data *b, int *keep)
{
	int	i;
	int	original_size;

	i = 0;
	original_size = a->size;
	while (i < original_size)
	{
		if (keep[i] == 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
}

static int	get_best_idx(t_data *a, t_data *b)
{
	int	i;
	int	best_idx;
	int	best_cost;
	int	curr_cost;

	i = 0;
	best_cost = 2147483647;
	best_idx = 0;
	while (i < b->size)
	{
		curr_cost = ft_abs(cost(find_target_pos(a, b->arr[i]), a->size))
			+ ft_abs(cost(i, b->size));
		if (curr_cost < best_cost)
		{
			best_cost = curr_cost;
			best_idx = i;
		}
		i++;
	}
	return (best_idx);
}

static void	move_best_from_b_to_a(t_data *a, t_data *b)
{
	int	best_idx;
	int	cost_a;
	int	cost_b;
	int	target_pos;

	best_idx = get_best_idx(a, b);
	cost_b = cost(best_idx, b->size);
	target_pos = find_target_pos(a, b->arr[best_idx]);
	cost_a = cost(target_pos, a->size);
	execute_move(a, b, cost_a, cost_b);
}

static void	rotate_to_min(t_data *a)
{
	int	min_val;
	int	min_pos;

	min_val = find_min(a);
	min_pos = find_index(a, min_val);
	if (min_pos <= a->size / 2)
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

void	sort(t_data *a, t_data *b)
{
	int	*lis;
	int	*prev;
	int	*keep;
	int	lis_end;

	lis = malloc(sizeof(int) * a->size);
	prev = malloc(sizeof(int) * a->size);
	keep = ft_calloc(a->size, sizeof(int));
	if (!lis || !prev || !keep)
		return ;
	compute_lis(a->arr, a->size, lis, prev);
	lis_end = get_lis_end(lis, a->size);
	mark_lis(keep, prev, lis_end);
	turkey(a, b, keep);
	free(lis);
	free(prev);
	free(keep);
	while (b->size > 0)
		move_best_from_b_to_a(a, b);
	rotate_to_min(a);
}
