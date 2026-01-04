/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:30:39 by taalmeid          #+#    #+#             */
/*   Updated: 2026/01/04 16:52:24 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_data *a)
{
	int	i;
	int	min;

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

int	find_max(t_data *a)
{
	int	i;
	int	max;

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

int	find_index(t_data *a, int value)
{
	int	i;

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

long	ft_atol(const char *str)
{
	long	i;
	long	sgn;
	long	result;

	i = 0;
	sgn = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sgn);
}

void	ss(t_data *a, t_data *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
