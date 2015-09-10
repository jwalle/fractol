#include "fractol.h"

int		frac_mandel(t_brot *in, t_env *e)
{
	t_brot	old;
	t_brot	new;

	int i;

	old.a = 0;
	old.b = 0;
	new.a = 0;
	new.b = 0;
	i = 0;
	while (i < e->iter)
	{
		old.a = new.a;
		old.b = new.b;
		new.a = old.a * old.a - old.b * old.b + in->a;
		new.b = 2 * old.a + old.b + in->b;
		if ((new.a * new.a + new.b * new.b) > 4)
			break ;
		i++;
	}
	if (i == e->iter)
		return (0);
	return (i);
}

int		ft_color(int i, t_env *e)
{
	int rgb[3];
	int col;

	if (i < 100)
	{
		rgb[0] = i * 15 / e->iter;
		rgb[1] = i * 255 / e->iter;
		rgb[2] = i * 15 / e->iter;
		col = ((rgb[2] & 0xff) << 16) + ((rgb[1] & 0xff) << 8) + rgb[0];
	}
	else if (i < 255)
	{
		rgb[0] = i * 1 / e->iter;
		rgb[1] = i * 10 / e->iter;
		rgb[2] = i * 255 / e->iter;
		col = ((rgb[2] & 0xff) << 16) + ((rgb[1] & 0xff) << 8) + rgb[0];
	}
	else
	{
		rgb[0] = i * 10 / e->iter;
		rgb[1] = i * 100 / e->iter;
		rgb[2] = i * 255 / e->iter;
		col = ((rgb[2] & 0xff) << 16) + ((rgb[1] & 0xff) << 8) + rgb[0];
	}
	return (col);
}

void	draw_case_one(t_env *e)
{
	int 		x;
	int 		y;
	t_brot		in;

	y = 0;
	x = 0;
	while (y <= WINDOW_HEIGHT)
	{
		while (x <= WINDOW_WIDE)
		{
			in.a = (x + e->up) / e->zoom / WINDOW_WIDE * 4 - 2;
			in.b = (y + e->dwn) / e->zoom / WINDOW_HEIGHT * 4 - 2;
			pxl_to_image(e, x, y, ft_color(frac_mandel(&in, e), e));
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_mandelbrot(t_env *e)
{
	draw_case_one(e);
	mlx_put_image_to_window(e->mlx, e->win_one, e->img_one, 0, 0);
}