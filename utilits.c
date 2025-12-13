/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:30:39 by taalmeid          #+#    #+#             */
/*   Updated: 2025/12/11 16:05:48 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void assign_index(t_data **stack_a)
{
    
}

void 

long ft_atol (char *str)
{
    long    i;
    long	sgn;
	long	result;
    
    i = 0;
	sgn = 1;
	result = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn *= -1;
		i++;
	}
    while (str[i] >= '0' && str[i] <= '9')
	{
        result = result * 10 + (str[i] - '0');
		i++;
	}
    return (result * sgn);
}
