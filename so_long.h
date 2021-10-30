#ifndef SO_LONG_H
#define SO_LONG_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include "./get_next_line/get_next_line.h"

typedef struct  s_ch
{
    int E_count;
    int P_count;
    int C_count;
    int V_count; 
}               m_ch;

typedef struct  s_data
{
    int     height;
    int     width;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

typedef struct  s_mem
{
    int             row_count;
    int             column_count;
    int             win_height;
    int             win_width;
    int             coor_x;
    int             coor_y;
    int             cool_count;
    int             result;
    int             check;
    void            *mlx;
    void            *mlx_win;
    char            **map;
    t_data          data;
    t_data          floor;
    t_data          wall;
    t_data          player;
    t_data          door;
    t_data          coll;
    t_data          stop;
}               l_mem;

m_ch    *ch_initialize(void);
char    *ch_initArray(int size);
int     *initArray(int size);

void    check_open(int fd);
void    check_count(m_ch *check, l_mem *mem);
void    check_EPC(char *str, int len, m_ch *check);
void    check_string1member(char *str, int i, int row_count, int arr_number);
int     check_string1member_flr(char *str);
int     check_string1member_flc(char *str, int size);
int     check_map_name(char *string, char *str);
int		check_map_number(char c);
int     check_map_size(int *arr, int len);

void	ft_putstr_fd(char *s, int fd);
int     ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
int		ft_lenght(int num);

void    get_row_count(char *argv, l_mem *mem);
void    get_columns_count(char *argv, l_mem *mem);

int		ft_countword(char *s, char c);
int		ft_wordlen(char *s, char c);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	**ft_split(char const *s, char c);

char    **get_map(char *argv, l_mem *mem);
void    get_init(l_mem *mem);
int     ft_game(int key, l_mem *mem);

int     draw(l_mem *mem);
int     rgb(int r, int g, int b);
int     get_pixel(t_data *img, int x, int y);
int     ft_close(l_mem *mem);
void    check_coll(l_mem *mem);
void    draw_map(l_mem *mem);
void    draw_player(l_mem *mem, int x, int y);
void    draw_image(l_mem *mem, int x, int y, t_data text);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif

