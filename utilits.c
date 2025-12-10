/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taalmeid <taalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:30:39 by taalmeid          #+#    #+#             */
/*   Updated: 2025/12/09 16:33:21 by taalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
    int i; 
    i = 0;

    while(str[i])
        i++;
    return(i);
}

int parsing(char *str)
{
int index; 
int rec = arr[0];
int len = ft_strlen(str);

while(*str)
    rec = *str++; 
return(rec);
}
