#include "fractol.h"

void	draw_case_one(t_env *e)
{
	int			x;
	int			y;
	int			color;
	int			color2;

	// x = ori->x;
	color = 0xFFFF00;
	color2 = 0xFFFF00;
	x = 0;
	while (x <= WINDOW_HEIGHT)
	{
		y = 0;
		while (y <= WINDOW_WIDE)
		{
			// color2 = ;
			pxl_to_image(e, x, y, color * x);
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