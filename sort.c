
#include "push_swap.h"

/* --- Funções Auxiliares Estáticas --- */

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	execute_move(t_data *a, t_data *b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
	pa(a, b);
}

/* --- Funções de LIS e Turkey --- */

void	compute_lis(int *arr, int size, int *lis, int *prev)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		lis[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	get_lis_end(int *lis, int size)
{
	int	i;
	int	max;
	int	idx;

	i = 0;
	max = 0;
	idx = 0;
	while (i < size)
	{
		if (lis[i] > max)
		{
			max = lis[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

void	mark_lis(int *keep, int *prev, int end)
{
	while (end != -1)
	{
		keep[end] = 1;
		end = prev[end];
	}
}



void    turkey(t_data *a, t_data *b, int *keep)
{
    int i;
    int original_size;

    i = 0;
    original_size = a->size;
    
    // Itera exatamente o número de vezes do tamanho original
    while (i < original_size)
    {
        // Se o elemento atual (que está no topo de A) faz parte da LIS
        if (keep[i] == 1) // Assumindo que keep[i] corresponde ao elemento que ESTAVA na posição i original
        {
            ra(a); // Mantém em A (manda para o fundo)
        }
        else
        {
            pb(a, b); // Não faz parte da LIS, manda para B
        }
        i++;
    }
}

/* --- Funções de Custo e Movimento --- */

int	cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

int	find_target_pos(t_data *a, int value)
{
	int	i;

	i = 0;
	if (value < find_min(a) || value > find_max(a))
		return (find_index(a, find_min(a)));
	while (i < a->size)
	{
		if (i == 0)
		{
			if (a->arr[i] > value && a->arr[a->size - 1] < value)
				return (i);
		}
		else if (a->arr[i] > value && a->arr[i - 1] < value)
			return (i);
		i++;
	}
	return (0);
}

void	move_best_from_b_to_a(t_data *a, t_data *b)
{
	int	i;
	int	best_idx;
	int	best_cost;
	int	cost_a;
	int	cost_b;
	int	target_pos;

	i = 0;
	best_cost = 2147483647; // INT_MAX
	best_idx = 0;
	while (i < b->size)
	{
		cost_b = cost(i, b->size);
		target_pos = find_target_pos(a, b->arr[i]);
		cost_a = cost(target_pos, a->size);
		if (ft_abs(cost_a) + ft_abs(cost_b) < best_cost)
		{
			best_cost = ft_abs(cost_a) + ft_abs(cost_b);
			best_idx = i;
		}
		i++;
	}
	cost_b = cost(best_idx, b->size);
	target_pos = find_target_pos(a, b->arr[best_idx]);
	cost_a = cost(target_pos, a->size);
	execute_move(a, b, cost_a, cost_b);
}

void	rotate_to_min(t_data *a)
{
	int	min_val;
	int	min_pos;

	min_val = find_min(a);
	min_pos = find_index(a, min_val);
	if (min_pos <= a->size / 2)
	{
		while (a->arr[0] != min_val)
			ra(a);
	}
	else
	{
		while (a->arr[0] != min_val)
			rra(a);
	}
}

/* --- Função Principal de Sort --- */

void	sort(t_data *a, t_data *b)
{
	int	*lis;
	int	*prev;
	int	*keep;
	int	lis_end;

	lis = malloc(sizeof(int) * a->size);
	prev = malloc(sizeof(int) * a->size);
	keep = ft_calloc(a->size, sizeof(int));
	if (!lis || !prev || !keep)
		return ; // Tratamento básico de erro de malloc
	compute_lis(a->arr, a->size, lis, prev);
	lis_end = get_lis_end(lis, a->size);
	mark_lis(keep, prev, lis_end);
	turkey(a, b, keep);
	free(lis);
	free(prev);
	free(keep);
	while (b->size > 0)
		move_best_from_b_to_a(a, b);
	rotate_to_min(a);
}