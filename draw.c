#include "so_long.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int   get_pixel(t_data *img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8))));
}

int   rgb(int r, int g, int b)
{
    return r | g << 8 | b << 16;
}

void  clear_map(l_mem *mem)
{
  int i;
  int j;

  i = 0;
  while (i < mem->win_height )
  {
    j = 0;
    while (j < mem->win_width)
    {
      int color = rgb(0, 0, 0);
      my_mlx_pixel_put(&mem->data, 0, 0, color);
      j++;
    }
    i++;
  }
}

int   draw(l_mem *mem)
{
  draw_map(mem);
  check_coll(mem);
  mlx_put_image_to_window(mem->mlx, mem->mlx_win, mem->data.img, 0, 0);
  mlx_put_image_to_window(mem->mlx, mem->mlx_win, mem->player.img, mem->coor_x * 64, mem->coor_y * 64);
  mlx_string_put(mem->mlx, mem->mlx_win, 20, 20, rgb(0,0,0),  "step = ");
  mlx_string_put(mem->mlx, mem->mlx_win, 100, 20, rgb(0, 0, 0),  ft_itoa(mem->result));
  return (1);
}

void    check_coll(l_mem *mem)
{
  if (mem->map[mem->coor_y][mem->coor_x] == 'C')
  {
    mem->cool_count--;
    mem->map[mem->coor_y][mem->coor_x] = '0';
  }
  else if ((mem->map[mem->coor_y][mem->coor_x] == 'E' && !mem->cool_count)
    || mem->map[mem->coor_y][mem->coor_x] == 'V')
    exit(0);
}

void    draw_floor(l_mem *mem)
{
  int i;
  int j;

  i = 0;
  while(i < mem->win_height)
  {
    j = 0;
    while (j < mem->win_width)
    {
      my_mlx_pixel_put(&mem->data, j, i, rgb(240,240,240));
      j++;
    }
    i++;
  }
}

void    draw_image(l_mem *mem, int x, int y, t_data text)
{
  int i;
  int j;

  i = 0;
  while (i < text.height)
  {
    j = 0;
    while (j < text.width)
    {
      unsigned int color = get_pixel(&text, j, i);
      my_mlx_pixel_put(&mem->data, x + j, y + i, (color ==
            0xff000000 ? rgb(240,240,240) : color));
      j++;
    }
    i++;
  }
}

void  draw_player(l_mem *mem, int x, int y)
{
  mem->map[y][x] = '0';
  mem->coor_x = (int)x;
  mem->coor_y = (int)y;
}

void  draw_map(l_mem *mem)
{
  int     i;
  int     j;

  draw_floor(mem);
  i = 0;
  while (i < mem->row_count)
  {
    j = 0;
    while (j < mem->column_count)
    {
      if (mem->map[i][j] == '1')
        draw_image(mem, j * 64, i * 64, mem->wall);
      else if (mem->map[i][j] == 'C')
        draw_image(mem, j * 64, i * 64, mem->coll);
      else if (mem->map[i][j] == 'V')
        draw_image(mem, j * 64, i * 64, mem->stop);
      else if (mem->map[i][j] == 'E')
        draw_image(mem, j * 64, i * 64, mem->door);
      else if (mem->map[i][j] == 'P')
        draw_player(mem, j, i);
      j++;
    }
    i++;
  }
}