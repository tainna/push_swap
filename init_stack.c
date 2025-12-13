
#include "push_swap.h"

static long ft_atol (char *str)
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

static  int has_duplicates(int *arr, int n)
{
    int i;
    int j;

    i = 0;
    while(i < n)
    {
        j = i + 1;
        while(j < n)
        {
            if(arr[i] == arr[j])
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}

static int  count_tokens(char **tokens)
{
    int i;

    i = 0;
    if(!tokens)
        return(0);
    while(tokens[i])
        i++;
    return(i);
}

static  void print_error_and_free(char **tokens, int need_free, t_data *s)
{
    int i;

    ft_printf("Error\n");
    if(need_free && tokens)
    {
        i = 0;
        while(tokens[i])
            free(tokens[i++]);
        free(tokens);    
    }
    if(s)
    {
        free(s->arr);
        free(s);
    }
}

static int  invalid_syntax(const char *s)
{
    int i;

    i = 0;
    if(!s || s[0] == '\0')
        return(1);
    if(s[i] == '+' || s[i] == '-')
        i++;
    if(s[i] == '\0')
        return(1);
    while(s[i])
    {
        if(s[i] < '0' || s[i] > '9')
            return(1);
        i++;
    }
    return(0);
}

int init_stack(t_data **dst, char **tokens, int need_free)
{
    t_data  *s;
    long    tmp;
    int i;
    int count;

    i = 0;
    count = count_tokens(tokens);
    if (count == 0)
        return (-1);
   
    s = malloc(sizeof(t_data));
    if (!s) 
        return (-1);
    s->arr = malloc(sizeof(int) * count);
    if (!s->arr)
    {
        free(s);
        return -1;
    }
    s->size = 0;
    s->capacity = count;

    while (tokens[i])
    {
        if (invalid_syntax(tokens[i]))
        {
            print_error_and_free(tokens, need_free, s);
            return (-1);
        }
        tmp = ft_atol(tokens[i]);
        if (tmp < INT_MIN || tmp > INT_MAX)
        {
            print_error_and_free(tokens, need_free, s);
            return (-1);
        }
        s->arr[s->size] = (int)tmp;
        s->size++;
        i++;
    }

    if (has_duplicates(s->arr, s->size))
    {
        print_error_and_free(tokens, need_free, s);
        return (-1);
    }
    *dst = s;
    return (0);
}
