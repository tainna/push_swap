/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:12:18 by taalmeid          #+#    #+#             */
/*   Updated: 2026/01/04 16:37:02 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_data *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rra(t_data *a)
{
	rrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_data *b)
{
	rrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_data *a, t_data *b)
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}

void	rr(t_data *a, t_data *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
