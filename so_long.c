#include "so_long.h"

int main(int argc, char **argv)
{
    l_mem       mem;

    if (argc == 2)
    {
        if (!check_map_name(argv[1], ".ber")) 
        {
            get_row_count(argv[1], &mem);   
            get_columns_count(argv[1], &mem);
            mem.win_height = mem.row_count * 64;
            mem.win_width = mem.column_count * 64;
            mem.map = get_map(argv[1], &mem);
            get_init(&mem);
        }
    }
    else
        ft_putstr_fd("Error, argc != 2", 2);
    return (0);
}