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

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <sys/time.h>
#include <stdio.h> // PRINTF

typedef struct	s_env
{
	int			color_set;
	void		*mlx;
	void		*win;
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


#endif
