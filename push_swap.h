/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:46:30 by taalmeid          #+#    #+#             */
/*   Updated: 2026/01/04 16:51:53 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/* INCLUDES                                  */
/* ************************************************************************** */

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* ************************************************************************** */
/* STRUCTS                                   */
/* ************************************************************************** */

typedef struct s_data
{
	int	*arr;
	int	size;
	int	capacity;
}		t_data;

/* ************************************************************************** */
/* INIT / PARSING                                */
/* ************************************************************************** */

int		init_stack(t_data **dst, char **tokens, int need_free);

/* ************************************************************************** */
/* BASIC OPERATIONS                              */
/* ************************************************************************** */

/* swap */
void	sa(t_data *a);
void	sb(t_data *b);

/* push */
void	pa(t_data *a, t_data *b);
void	pb(t_data *a, t_data *b);

/* rotate */
void	ra(t_data *a);
void	rb(t_data *b);
void	rr(t_data *a, t_data *b);

/* reverse rotate */
void	rra(t_data *a);
void	rrb(t_data *b);
void	rrr(t_data *a, t_data *b);

/* ************************************************************************** */
/* INTERNAL STACK MANIPULATION                          */
/* ************************************************************************** */

void	push(t_data *src, t_data *dst);
void	swap(t_data *src);
void	rotate(t_data *src);
void	rrotate(t_data *src);

/* ************************************************************************** */
/* SORT SMALL                                    */
/* ************************************************************************** */

void	is_three(t_data *a);
void	is_five(t_data *a, t_data *b);
int		is_sorted(t_data *a);

/* ************************************************************************** */
/* LIS                                      */
/* ************************************************************************** */

void	compute_lis(int *arr, int size, int *lis, int *prev);
int		get_lis_end(int *lis, int size);
void	mark_lis(int *keep, int *prev, int end);

/* ************************************************************************** */
/* TURKEY                                    */
/* ************************************************************************** */

void	rotate_keep(int *keep, int size);

/* ************************************************************************** */
/* COST / TARGET / MOVE                                */
/* ************************************************************************** */

long	ft_atol(const char *str);
int		ft_abs(int n);
int		cost(int pos, int size);
int		find_min(t_data *a);
int		find_max(t_data *a);
int		find_index(t_data *a, int value);
int		find_target_pos(t_data *a, int value);
void	execute_move(t_data *a, t_data *b, int cost_a, int cost_b);

/* ************************************************************************** */
/* MAIN ALGORITHM                                 */
/* ************************************************************************** */

void	algoritm(t_data *a);
void	sort(t_data *a, t_data *b);

#endif