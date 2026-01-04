/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:31:20 by taalmeid          #+#    #+#             */
/*   Updated: 2026/01/04 16:10:21 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include "push_swap.h"

void	free_resources(t_data *a, char **tokens, int need_free)
{
	int	i;

	if (a)
	{
		free(a->arr);
		free(a);
	}
	if (need_free && tokens)
	{
		i = 0;
		while (tokens[i])
			free(tokens[i++]);
		free(tokens);
	}
}

int	main(int ac, char **av)
{
	t_data	*a;
	char	**tokens;
	int		need_free;

	a = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		return (ft_printf("Error\n"), 1);
	if (ac == 2)
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
		return (1);
	algoritm(a);
	free_resources(a, tokens, need_free);
	return (0);
}
