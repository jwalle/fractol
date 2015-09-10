/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 17:39:01 by jwalle            #+#    #+#             */
/*   Updated: 2015/09/07 18:15:10 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# define WINDOW_WIDE 800
# define WINDOW_HEIGHT 800
# define MAPS "modulo | julia"

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <sys/time.h>
#include <stdio.h> // PRINTF

typedef struct	s_env
{
	int			windows;
	int			color_set;
	void		*mlx;
	void		*win_one;
	void		*win_two;
	char		*frac_one;
	char		*frac_two;
	void		*img_one;
	void		*img_two;
	char		*data_one;
	char		*data_two;
	void		*img;
	int			bpp;
	int			sl;
	int			endian;
	double		zoom;
	double		lft;
	double		rgt;
	double		up;
	double		dwn;
	double		b;
	double		last_time;
	int			iter;
}				t_env;

typedef struct	s_brot
{
	int			plop;
	double		a;
	double		b;
}				t_brot;


int		expose_hook(t_env *e);
int		key_hook(int keycode, t_env *e);
void	ft_loop_two(t_env *e);
void	ft_loop_one(t_env *e);
void	draw_mandelbrot(t_env *e);
void	pxl_to_image(t_env *e, int x, int y, uint32_t color);

#endif
