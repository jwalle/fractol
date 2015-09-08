
#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
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
	if (keycode == 47)
		e->z += 1;
	if (keycode == 43)
		e->z -= 1;
	if (keycode == 6)
		e->z += 0.1;
	if (keycode == 7)
		e->z -= 0.1;
	mlx_clear_window(e->mlx, e->win_one);
	mlx_destroy_image(e->mlx, e->img_one);
	expose_hook(e);
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
