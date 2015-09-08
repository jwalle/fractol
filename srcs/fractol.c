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

void	print_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	pxl_to_image(t_env *e, int x, int y, uint32_t color)
{
	int pixel;

	pixel = 1;
	if (x > 0 && x < WINDOW_WIDE && y > 0 && y < WINDOW_HEIGHT)
	{
		pixel = (x * e->sl) + (y * (e->bpp / 8));
		ft_memcpy(e->data_one + pixel, &color, e->bpp / 8);
	}
}

void	ft_reset(t_env *e)
{
	//e->zoom = 10;
	e->color_set = 1;
}

void	init_window(t_env *e, char *name, int windows)
{
	if (!windows)
	{
		e->win_one = mlx_new_window(e->mlx, WINDOW_WIDE, WINDOW_HEIGHT, name);
		printf("ONE WIN\n");
		return ;
	}
	else if (windows)
	{
		if (windows == 1)
			e->win_one = mlx_new_window(e->mlx, WINDOW_WIDE, WINDOW_HEIGHT, name);
		else if (windows == 2)
			e->win_two = mlx_new_window(e->mlx, WINDOW_WIDE, WINDOW_HEIGHT, name);
	}
}


void	ft_init(t_env *e)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	e->last_time = time.tv_sec + time.tv_usec * 1e-6;
	e->img_one = NULL;
	e->lft = 1;
	e->rgt = 1;
	e->up = 1;
	e->dwn = 1;
	e->zoom = 1.2;
	//ft_reset(e);
}

int		main(int ac, char **av)
{
	t_env *e;

	e = malloc(sizeof(t_env));
	if (ac == 1)
	{
		print_error("Error, select at least one map to display.");
		return (1);
	}
	ft_init(e);
	e->mlx = mlx_init();
	if (ac == 2)
	{
		if (ft_strstr(av[1], "julia"))
		{
			printf("PLOP\n");
			init_window(e, av[1], 0);
			ft_loop_one(e);
			return (0);
		}
		else
			print_error("Error, select a valid map.");
	}
	if (ac == 3)
	{
		if (ft_strstr(av[1], MAPS) && ft_strstr(av[2], MAPS))
		{
			e->frac_one = ft_strdup(av[1]);
			e->frac_two = ft_strdup(av[2]);
			init_window(e, av[1], 1);
			init_window(e, av[1], 2);
			ft_loop_two(e);
			return (0);
		}
		else
			print_error("Error, select a valid map.");
	}
	return (0);
}
