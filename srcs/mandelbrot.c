#include "fractol.h"

int		frac_mandel(int x, int y, t_env *e)
{
	int a;
	int b;
	int i;
	int j;

	a = x;
	b = y;
	i = 4;
	j = 6;
	(void)e;

		while (i < 150)
		{
			x = a * a - b * b + i;
			y = 2 * a + b + j;
			if ((x * x + y * y) > 4)
				return(i);
		}
		return (i);
}

void	draw_case_one(t_env *e)
{
	int			x;
	int			y;
	int			color;
	int			color2;

	// x = ori->x;
	color = 0xFFFF00;
	x = 0;
	while (x <= WINDOW_HEIGHT)
	{
		y = 0;
		while (y <= WINDOW_WIDE)
		{
			color2 = frac_mandel(x, y, e);
			pxl_to_image(e, x, y, color2);
			y++;
		}
		x++;
	}
}

void	draw_mandelbrot(t_env *e)
{
	draw_case_one(e);
	mlx_put_image_to_window(e->mlx, e->win_one, e->img_one, 0, 0);
}