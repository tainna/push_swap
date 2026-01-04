/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:00:48 by taalmeid          #+#    #+#             */
/*   Updated: 2026/01/04 15:46:14 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift(int *arr, int size, int direction)
{
	int	i;

	if (direction == 1)
	{
		i = size;
		while (i > 0)
		{
			arr[i] = arr[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < size - 1)
		{
			arr[i] = arr[i + 1];
			i++;
		}
	}
}

void	push(t_data *src, t_data *dst)
{
	int	val;

	if (src->size == 0)
		return ;
	val = src->arr[0];
	shift(dst->arr, dst->size, 1);
	dst->arr[0] = val;
	dst->size++;
	shift(src->arr, src->size, 0);
	src->size--;
}

void	swap(t_data *src)
{
	int	val;

	if (src->size == 0 || src->size == 1)
		return ;
	val = src->arr[0];
	src->arr[0] = src->arr[1];
	src->arr[1] = val;
}

void	rotate(t_data *src)
{
	int	val;

	if (src->size <= 1)
		return ;
	val = src->arr[0];
	shift(src->arr, src->size, 0);
	src->arr[src->size - 1] = val;
}

void	rrotate(t_data *src)
{
	int	val;

	if (src->size <= 1)
		return ;
	val = src->arr[src->size - 1];
	shift(src->arr, src->size - 1, 1);
	src->arr[0] = val;
}
