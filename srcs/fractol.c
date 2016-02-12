/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:09:53 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/12 20:04:39 by amoinier         ###   ########.fr       */
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
	init->x1 = -2.1;
	init->x2 = 1.5;
	init->y1 = -1.2;
	init->y2 = 1.2;
	init->zoomx = (init->x2 - init->x1) * 200;
	init->zoomy = (init->y2 - init->y1) * 200;
	init->width = init->zoomx;
	init->height = init->zoomy;
	if (ft_strequ(av, "sierp"))
	{
		init->width = 800;
		init->height = 800;
	}
	init->iter = 30;
	init->col = 0xffffff + 33333333;
	init->julx = 0;
	init->july = 0;
	init->movex = 0;
	init->movey = 0;
	init->zoom = 10.00000000;
	init->fixjul = 0;
	init->img = ft_init_img(init);
}

int				control_param(char *av)
{
	if (ft_strequ(av, "mandel") || ft_strequ(av, "julia") ||
	ft_strequ(av, "sierp") || ft_strequ(av, "douady") ||
	ft_strequ(av, "burning"))
		return (1);
	else
		return (0);
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
			mlx_hook(init->win, 2, 0, key_hook, init);
			if (ft_strequ(av[1], "julia"))
				mlx_hook(init->win, 6, 0, mouse_julia, init);
			mlx_hook(init->win, 4, 0, mouse_hook, init);
			mlx_expose_hook(init->win, expose_hook, init);
			mlx_loop(init->mlx);
		}
		else
			ft_putstr("USAGE : mandel - julia - douady - burning - sierp\n");
	}
	else
		ft_putstr("USAGE : 1 param\n");
	return (0);
}
