/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:31:06 by taalmeid          #+#    #+#             */
/*   Updated: 2025/12/13 19:45:42 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#endif

typedef struct s_data
{
    int *arr;
    int size;
    int capacity;
            
    struct  s_data *target;
    struct  s_data *next;
    struct  s_data *prev;
}   t_data;