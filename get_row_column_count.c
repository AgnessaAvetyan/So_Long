#include "so_long.h"

void    get_row_count(char *argv, l_mem *mem)
{
    int     fd;
    int     res;
    char    *line;

    res = 0;
    fd = open(argv, O_RDONLY);
    check_open(fd);
    while ((res = get_next_line(fd, &line)) > 0)
        mem->row_count++;
    if (res == -1)
        ft_putstr_fd("Error", 2);
    else if (res == 0)
        mem->row_count++;
    close(fd);
}

void    get_columns_count(char *argv, l_mem *mem)
{
    int     fd;
    int     i;
    int     *array;
    char    *str;
    char    *line;
    m_ch    *check;

    i = -1;
    check = ch_initialize();
    fd = open(argv, O_RDONLY);
    check_open(fd);
    array = initArray(mem->row_count);
    while (++i < mem->row_count)
    {
        str = get_next_line_string(fd, &line, mem->row_count);
        array[i] = ft_strlen(str);
        check_EPC(str, array[i], check);
        check_string1member(str, i, mem->row_count, array[i]);
        free(str);
    }
    check_count(check, mem);
    mem->column_count = check_map_size(array, mem->row_count);
    close(fd);
    free(array);
    free(check);
}