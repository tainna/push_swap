/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:31:06 by taalmeid          #+#    #+#             */
/*   Updated: 2025/12/10 18:05:29 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#ifndef PUSH_SWAP_H
#def PUSH_SWAP_H

typedef struct s_data
{
    int value;
    int position;
    int push_price;
    int final_index;
    bool keep_a;
    bool cheapest;
    bool above;
    struct  s_data *target;
    struct  s_data *next;
    struct  s_data *prev;
}   t_data;
