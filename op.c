/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tainna <tainna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:22:44 by taalmeid          #+#    #+#             */
/*   Updated: 2025/12/26 20:57:03 by tainna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void    pb(t_data *a, t_data *b)
{
    push(a, b);
    ft_printf("pb\n");
}

void    pa(t_data *a, t_data *b)
{
    push(b, a);
    ft_printf("pa\n");
}

void    sa(t_data *a)
{
    swap(a);
    ft_printf("sa\n");
}

void    sb(t_data *b)
{
    swap(b);
    ft_printf("sb\n");
}

void    ra(t_data *a)
{
    rotate(a);
    ft_printf("ra\n");
}

void    rb(t_data *b)
{
    rotate(b);
    ft_printf("rb\n");
}

void    rra(t_data  *a)
{
    rrotate(a);
    ft_printf("rra\n");
}

void    rrb(t_data  *b)
{
    rrotate(b);
    ft_printf("rrb\n");
}

void    rrr(t_data *a, t_data *b)
{
    rrotate(a);
    rrotate(b);
    ft_printf("rrr\n");
}

void    rr(t_data *a, t_data *b)
{
    rotate(a);
    rotate(b); 
    ft_printf("rr\n");
}

void    ss(t_data *a, t_data *b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}