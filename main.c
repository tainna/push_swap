/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tainna <tainna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:31:20 by taalmeid          #+#    #+#             */
/*   Updated: 2025/12/26 15:46:07 by tainna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

int main(int ac, char **av)
{
    t_data *a = NULL;
   
    char **tokens = NULL;
    int need_free = 0;

    if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
    {
       ft_printf("Error\n"); //inserir o printf nas ref
        return (1);
    }
    else if (ac == 2)
    {
        tokens = ft_split(av[1], ' ');
        need_free = 1;
    }
    else
    {
        tokens = av + 1; 
        need_free = 0;
    }

    if (init_stack(&a, tokens, need_free) == -1)
        return 1;
    algoritm(a);
    free(a->arr);
    free(a);
    if (need_free)
    {
        int i = 0;
        while (tokens[i])
            free(tokens[i++]);
        free(tokens);
    }
    return 0;
}
  
