/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 17:38:22 by jwalle            #+#    #+#             */
/*   Updated: 2015/09/07 18:15:44 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pxl_to_image(t_env *e, int x, int y, uint32_t color)
{
	int pixel;

	pixel = 1;
	if (x > 0 && x < WINDOW_SIZE_X && y > 0 && y < WINDOW_SIZE_Y)
	{
		pixel = (x * e->sl) + (y * (e->bpp / 8));
		ft_memcpy(e->data + pixel, &color, e->bpp / 8);
	}
}

void	ft_reset(t_env *e)
{
	e->zoom = 10;
	e->a = 34;
	e->b = 39.9;
	e->color_set = 1;
}

void	ft_init(t_env *e)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	e->last_time = time.tv_sec + time.tv_usec * 1e-6;
	ft_reset(e);
}

int		main(int ac, char **av)
{
	t_env e;
	
	if (ac == 1)
	{
		ft_putstr("Error, select at least one map to display.\n");
		return (1);
	}
	ft_init(&e);
	if (ac < 4)
	{
		if (ft_strequ(av[1], "modulo"))
	}
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);	return (0);
}
