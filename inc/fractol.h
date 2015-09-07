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

# define WINDOW_WIDE 1000
# define WINDOW_HEIGHT 1000
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
	void		*data_one;
	void		*data_two;
	void		*img;
	int			bpp;
	int			sl;
	int			endian;
	double		w;
	double		z;
	double		g;
	double		a;
	double		b;
	double		last_time;
}				t_env;

int		expose_hook(t_env *e);
int		key_hook(int keycode, t_env *e);
void	ft_loop_two();
void	ft_loop_one();

#endif
