#include "so_long.h"

char    **get_map(char *argv, l_mem *mem)
{
  char    **arr;
  char    *buff;
  int     rvalue;
  int     fd;

  fd = open(argv, O_RDONLY);
  check_open(fd);
  if (mem->column_count == 0 || mem->row_count == 0)
  {
    ft_putstr_fd("Error: Invalid map", 2);
    exit(0);
  }
  if (!(buff = malloc(sizeof(char) * ((mem->column_count + 1) * mem->row_count + 1))))
  {
    ft_putstr_fd("Error: Malloc", 2);
    exit(0);
  }  
  if ((rvalue = read(fd, buff, (mem->column_count + 1) * (mem->row_count + 1))) != -1)
  {
    arr = ft_split(buff, '\n');
    free(buff);
  }
  close(fd);
  return (arr);
}

int   iswall(l_mem *mem, int x, int y)
{
  if (mem->map[y][x] == '1')
    return (1);
  return (0);
}

int ft_check(int key, l_mem *mem)
{
  if (key == 13 || key == 0 || key == 1 || key == 2)
    mem->check = 0;
  return (1);
}

int   ft_game(int key, l_mem *mem)
{
  if (key == 13 && !iswall(mem, mem->coor_x, mem->coor_y - 1))
  {
    mem->coor_y--;
    mem->result++;
    printf("Number of step %d\n", mem->result);
  }
  else if (key == 0 && !iswall(mem, mem->coor_x - 1, mem->coor_y))
  {
    mem->coor_x--;
    mem->result++;
    printf("Number of step %d\n", mem->result);
  }
  else if (key == 2 && !iswall(mem, mem->coor_x + 1, mem->coor_y))
  {
    mem->coor_x++;
    mem->result++;
    printf("Number of step %d\n", mem->result);
  }
  else if (key == 1 && !iswall(mem, mem->coor_x, mem->coor_y + 1))
  {
    mem->coor_y++;
    mem->result++;
    printf("Number of step %d\n", mem->result);
  }
  else if (key == 53)
    ft_close(mem);
  return (1);
}

void    init_images(l_mem *mem)
{
    mem->data.img = mlx_new_image(mem->mlx, mem->win_width, mem->win_height);
    mem->wall.img = mlx_xpm_file_to_image(mem->mlx, "./src/wall.xpm", &mem->wall.width, &mem->wall.height);
    mem->coll.img = mlx_xpm_file_to_image(mem->mlx, "./src/collectible.xpm", &mem->coll.width, &mem->coll.height);
    mem->door.img = mlx_xpm_file_to_image(mem->mlx, "./src/door.xpm", &mem->door.width, &mem->door.height);
    mem->player.img = mlx_xpm_file_to_image(mem->mlx, "./src/player.xpm", &mem->player.width, &mem->player.height);
    mem->stop.img = mlx_xpm_file_to_image(mem->mlx, "./src/stop.xpm", &mem->stop.width, &mem->stop.height);
}

void  get_init(l_mem *mem)
{
  mem->mlx = mlx_init();
  mem->mlx_win = mlx_new_window(mem->mlx, mem->column_count * 64,
        mem->row_count * 64, "So_long");
  init_images(mem);
  mem->data.addr = mlx_get_data_addr(mem->data.img, &mem->data.bits_per_pixel,
        &mem->data.line_length, &mem->data.endian);
  mem->stop.addr = mlx_get_data_addr(mem->stop.img, &mem->stop.bits_per_pixel,
        &mem->stop.line_length, &mem->stop.endian);
  mem->wall.addr = mlx_get_data_addr(mem->wall.img, &mem->wall.bits_per_pixel,
        &mem->wall.line_length, &mem->wall.endian);
  mem->coll.addr = mlx_get_data_addr(mem->coll.img, &mem->coll.bits_per_pixel,
        &mem->coll.line_length, &mem->coll.endian);
  mem->door.addr = mlx_get_data_addr(mem->door.img, &mem->door.bits_per_pixel,
        &mem->door.line_length, &mem->door.endian);
  mem->player.addr = mlx_get_data_addr(mem->player.img, &mem->player.bits_per_pixel,
        &mem->player.line_length, &mem->player.endian);
  mlx_loop_hook(mem->mlx, draw, mem);
  mlx_hook(mem->mlx_win, 17, 1L << 17 ,ft_close, mem);
  mlx_hook(mem->mlx_win, 2, 1L << 0 ,ft_game, mem);
  mlx_hook(mem->mlx_win, 3, 1L << 0 ,ft_check, mem);
  mlx_loop(mem->mlx);
}

int ft_close(l_mem *mem)
{
  mlx_destroy_window(mem->mlx, mem->mlx_win);
  exit(0);
}