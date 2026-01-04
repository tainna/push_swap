/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:26:01 by taalmeid          #+#    #+#             */
/*   Updated: 2026/01/04 16:35:36 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compute_lis(int *arr, int size, int *lis, int *prev)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		lis[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	get_lis_end(int *lis, int size)
{
	int	i;
	int	max;
	int	idx;

	i = 0;
	max = 0;
	idx = 0;
	while (i < size)
	{
		if (lis[i] > max)
		{
			max = lis[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

void	mark_lis(int *keep, int *prev, int end)
{
	while (end != -1)
	{
		keep[end] = 1;
		end = prev[end];
	}
}
