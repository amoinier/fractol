/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:09:53 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/16 12:53:35 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	t_img	*ft_init_img(t_env *init)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		error();
	img->img = mlx_new_image(init->mlx, init->width, init->height);
	img->bpp = 0;
	img->sizel = 0;
	img->endn = 0;
	img->cimg = mlx_get_data_addr(img->img, &img->bpp, &img->sizel, &img->endn);
	return (img);
}

static	void	ft_initenv(t_env *init, char *av)
{
	init->fract = av;
	init->x1 = -1.5;
	init->x2 = 1.5;
	init->y1 = -1.5;
	init->y2 = 1.5;
	init->width = (init->x2 - init->x1) * 200;
	init->height = (init->y2 - init->y1) * 200;
	init->iter = 30;
	init->julx = 0;
	init->july = 0;
	init->movex = 0;
	init->movey = 0;
	init->zoom = 1;
	init->fixjul = 0;
	init->col = 0xfff0ff;
	init->img = ft_init_img(init);
}

int				control_param(char *av)
{
	if (ft_strequ(av, "mandelbrot") || ft_strequ(av, "julia") ||
	ft_strequ(av, "sierpinski") || ft_strequ(av, "douady") ||
	ft_strequ(av, "burningship"))
		return (1);
	else
		return (0);
}

static	void	mlx_var(t_env *init)
{
	mlx_hook(init->win, 2, 0, key_hook, init);
	mlx_hook(init->win, 6, 0, mouse_julia, init);
	mlx_hook(init->win, 4, 0, mouse_hook, init);
	mlx_expose_hook(init->win, expose_hook, init);
	mlx_loop(init->mlx);
}

int				main(int ac, char **av)
{
	t_env	*init;

	if (ac == 2)
	{
		if (control_param(av[1]))
		{
			if (!(init = (t_env *)malloc(sizeof(*init))))
				error();
			init->mlx = mlx_init();
			ft_initenv(init, av[1]);
			init->win = mlx_new_window(init->mlx, init->width, init->height,
			"Fractol");
			mlx_var(init);
		}
		else
		{
			ft_putstr("USAGE : mandelbrot - julia - douady - ");
			ft_putstr("burningship - sierpinski\n");
		}
	}
	else
		ft_putstr("USAGE : 1 param\n");
	return (0);
}
