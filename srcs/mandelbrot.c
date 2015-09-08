#include "fractol.h"

int		frac_mandel(t_brot *in)
{
	t_brot	old;
	t_brot	new;

	int i;

	new.a = 0;
	new.b = 0;
	i = 0;
	while (i < 150)
	{
		old.a = new.a;
		old.b = new.b;
		new.a = old.a * old.a - old.b * old.b + in->a;
		new.b = 2 * old.a + old.b + in->b;
		if ((new.a * new.a + new.b * new.b) > 4)
			break ;
		i++;
	}
	if (i == 150)
		return (0);
	return (i);
}

int		ft_color(int i)
{
	int r;
	int g;
	int b;
	int col;

	r = i * 15 / 150;
	g = i * 255 / 150;
	b = i * 15 / 150;
	col = ((b & 0xff) << 16) + ((g & 0xff) << 8) + r;
	return (col);
}

void	draw_case_one(t_env *e)
{
	int 		x;
	int 		y;
	t_brot		in;

	y = 0;
	while (y <= WINDOW_HEIGHT)
	{
		x = 0;
		while (x <= WINDOW_WIDE)
		{
			in.a = (x + e->up) / e->zoom / WINDOW_WIDE * 4 - 2;
			in.b = (y + e->dwn) / e->zoom / WINDOW_HEIGHT * 4 - 2;
			pxl_to_image(e, x, y, ft_color(frac_mandel(&in)));
			x++;
		}
		y++;
	}
}

void	draw_mandelbrot(t_env *e)
{
	draw_case_one(e);
	mlx_put_image_to_window(e->mlx, e->win_one, e->img_one, 0, 0);
}