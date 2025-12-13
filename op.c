#include "push_swap.h"

static void shift(int *arr, int size, int direction)
{
    int i;

    if(direction == 1)
    {
        i == size;
        while(i > 0)
        {
            arr[i] = arr[i - 1];
            i--;
        }
    }
}

void    pb(t_data **a, t_data **b)
{
    int i;
    int j;
    t_data tmp;

    i = 0;
    j = 0;
    while(a[i] && b[j])
    {
        a->data = tmp;
        b[j] = tmp;
        free(a->data);

    }
}