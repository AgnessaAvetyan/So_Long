#include "so_long.h"

char    *ch_initArray(int size)
{
    char *array;

    if (!(array = (char *)malloc(size * sizeof(char))))
    {
        ft_putstr_fd("ERROR Malloc\n", 2);
        exit(0);
    }
    return (array);
}

int     *initArray(int size)
{
    int *array;

    if (!(array = (int *)malloc(size * sizeof(int))))
    {
        ft_putstr_fd("ERROR Malloc\n", 2);
        exit(0);
    }
    return (array);
}

m_ch   *ch_initialize(void)
{
    m_ch *mem;

    if (!(mem = (m_ch *)malloc(sizeof(m_ch))))
    {
        ft_putstr_fd("Malloc Error", 2);
        exit(0);
    }
    mem->C_count = 0;
    mem->E_count = 0;
    mem->P_count = 0;
    mem->V_count = 0;
    return (mem);
}