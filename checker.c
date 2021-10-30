#include "so_long.h"

int     check_map_name(char *string, char *str)
{
    int     i;
    int     j;
    int     len;
    char    *temp;

    len = ft_strlen(string);
    i = 0;
    while (string[i] && string[i] != '.')
        i++;
    j = 0;
    temp = ch_initArray(len - i);
    while(string[i] && i != 0)
    {
        temp[j] = string[i];
        i++;
        j++;
    }
    temp[j] = '\0';
    len = ft_strlen(temp);
    if (!ft_strncmp(temp, str, len))
        if(temp[j] == '\0' && str[4] == '\0')
        {
            free(temp);
            return (0);
        }
    free(temp);
    ft_putstr_fd("Error, map's format isn't .ber", 2);
    exit(0);
}

void    check_open(int fd)
{
    if (fd < 0)
    {
        ft_putstr_fd("An error has occured at opening the file", 2);
        exit(0);
    }
}

int    check_map_size(int *arr, int len)
{
    int check;
    int i;

    i = 0;
    check = arr[0];
    while (++i < len)
    {
        if (arr[i] != check)
        {
            ft_putstr_fd("The map size is incorrect", 2);
            exit(0);
        }
    }
    return (check);
}

void    check_EPC(char *str, int len, m_ch *check)
{
    int i;

    i = 1;
    while (i < len)
    {
        if (str[i] == 'E')
            check->E_count++;
        else if (str[i] == 'P')
            check->P_count++;
        else if (str[i] == 'C')
            check->C_count++;
        else if (str[i] == 'V')
            check->V_count++;
        else if (str[i] != '0' && str[i] != '1')
        {
            free(str);
            ft_putstr_fd("it is not map number", 2);
            exit(0);
        }       
        i++;
    }
}

int     check_string1member_flr(char *str)
{
    int i;

    i = -1;
    while (str[++i] != '\0')
    {
        if (str[i] != '1')
        {
            free(str);
            ft_putstr_fd("Error: border line have", 2);
            exit(0);
        }
    }
    return (0);
}

int     check_string1member_flc(char *str, int size)
{
    if (str[0] != '1' || str[size - 1] != '1' )
    {
        free(str);
        ft_putstr_fd("Error: border line have", 2);
        exit(0);
    }
    return (0);
}

void    check_string1member(char *str, int i, int row_count, int arr_number)
{
    if (i == 0 || i == row_count - 1)
        check_string1member_flr(str);
    else
        check_string1member_flc(str, arr_number);
}

void    check_count(m_ch *check, l_mem *mem)
{
    if (check->C_count <= 0 || check->E_count != 1 || check->P_count != 1)
    {
        ft_putstr_fd("Error map", 2);
        free(check);
        exit(0);
    }
    else
        mem->cool_count = check->C_count;
}