/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:22:44 by taalmeid          #+#    #+#             */
/*   Updated: 2025/12/14 18:49:15 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void    pb(t_data *a, t_data *b)
{
    push(a, b);
    ft_printf("pb");
}

void    pa(t_data *a, t_data *b)
{
    push(b, a);
    ft_printf("pa");
}

void    sa(t_data *a)
{
    swap(a);
    ft_printf("sa");
}

void    sa(t_data *b)
{
    swap(b);
    ft_printf("sb");
}

void    ra(t_data *a)
{
    rotate(a);
    ft_printf("ra");
}

void    rb(t_data *b)
{
    rotate(b);
    ft_printf("rb");
}

void    rra(t_data  *a)
{
    rrotate(a);
    ft_printf(rra);
}

void    rrb(t_data  *b)
{
    rrotate(b);
    ft_printf(rrb);
}

void    rrr(t_data *a, t_data *b)
{
    rra(a);
    rrb(b);
    ft_printf("rrr");
}