
#include "fractol.h"

void	ft_loop_one(t_env *e)
{
	mlx_expose_hook(e->win_one, expose_hook, e);
	printf("PLOP 1\n");
	mlx_key_hook(e->win_one, key_hook, e);
	printf("PLOP 2\n");
	//mlx_loop_hook(e->mlx, expose_hook, e);
	mlx_loop(e->mlx);
	printf("PLOP 3\n");
}

void	ft_loop_two(t_env *e)
{
	(void)e;
	printf("ONNNNE");	
}