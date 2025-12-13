

int ft_strrlen(char **str)
{
    int len;
    int i;
    int j;

    len = 0;
    i = 0;
    while(str[i][j])
    {
        j = 0;
        while(str[i][j])
            j++;
        len = len + j + 1;
        i++;
    }
    return(len);
}

void ft_args(int ac, char **av)
{
    int i;
    int len;


    len = ft_strlen(str);

}