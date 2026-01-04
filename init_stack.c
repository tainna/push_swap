/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:45:35 by taalmeid          #+#    #+#             */
/*   Updated: 2026/01/04 17:55:12 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

static int	has_duplicates(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	count_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return (0);
	while (tokens[i])
		i++;
	return (i);
}

static void	print_error_and_free(char **tokens, int need_free, t_data *s)
{
	int	i;

	ft_printf("Error\n");
	if (need_free && tokens)
	{
		i = 0;
		while (tokens[i])
			free(tokens[i++]);
		free(tokens);
	}
	if (s)
	{
		free(s->arr);
		free(s);
	}
}

static int	invalid_syntax(const char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == '\0')
		return (1);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	init_stack(t_data **dst, char **tokens, int need_free)
{
	t_data	*s;
	long	tmp;
	int		i;

	s = malloc(sizeof(t_data));
	if (!s)
		return (-1);
	s->capacity = count_tokens(tokens);
	s->arr = malloc(sizeof(int) * s->capacity);
	if (!(s->arr) || !(s->capacity))
		return (free(s), -1);
	s->size = 0;
	i = -1;
	while (tokens[++i])
	{
		tmp = ft_atol(tokens[i]);
		if (invalid_syntax(tokens[i]) || tmp < INT_MIN || tmp > INT_MAX)
			return (print_error_and_free(tokens, need_free, s), -1);
		s->arr[s->size++] = (int)tmp;
	}
	if (has_duplicates(s->arr, s->size))
		return (print_error_and_free(tokens, need_free, s), -1);
	*dst = s;
	return (0);
}
