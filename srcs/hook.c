
#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
	printf("keycode = %i", keycode);
	if (keycode == 53)
	{
		//free_tab_int(e->tab);
		mlx_clear_window(e->mlx, e->win_one);
		mlx_destroy_image(e->mlx, e->img_one);
		mlx_destroy_window(e->mlx, e->win_one);
		exit(0);
	}
	//ft_key1(keycode, e);
	//ft_key2(keycode, e);
	if (keycode == 126)
		e->rgt += 5;
	if (keycode == 125)
		e->rgt -= 5;
	if (keycode == 123)
		e->dwn += 10;
	if (keycode == 124)
		e->dwn -= 10;
	if (keycode == 69)
		e->zoom *= 1.1;
	if (keycode == 78)
		e->zoom /= 1.1;
	mlx_clear_window(e->mlx, e->win_one);
	mlx_destroy_image(e->mlx, e->img_one);
	expose_hook(e);
	return (1);
}

int		move_hook(int x, int y, t_env *e)
{
	printf("x = %i, y = %i iter = %i\n", x, y, e->iter);
	return (0);
}

int		mouse_hook(int button, t_env *e)
{
	printf("button = %i", button);
	if (button == 1) // left click
		e->rgt += 5;
	if (button == 2) // right click
		e->rgt -= 5;
	if (button == 4) // molette up
		e->zoom += 10;
	if (button == 4) // molette down
		e->zoom -= 10;
	if (button == 69)
		e->zoom *= 1.1;
	if (button == 78)
		e->zoom /= 1.1;
	//mlx_clear_window(e->mlx, e->win_one);
	//mlx_destroy_image(e->mlx, e->img_one);
	//expose_hook(e);
	return (1);
}


int		expose_hook(t_env *e)
{
	e->img_one = mlx_new_image(e->mlx, WINDOW_WIDE, WINDOW_HEIGHT);
	e->data_one = mlx_get_data_addr(e->img_one, &e->bpp, &e->sl, &e->endian);
	draw_mandelbrot(e);
	//ft_print_screen(e);
	return (0);
}
