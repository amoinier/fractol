/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:09:53 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/09 17:54:35 by amoinier         ###   ########.fr       */
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
	init->zoomx = (init->x2 - init->x1) * 300;
	init->zoomy = (init->y2 - init->y1) * 300;
	init->width = (init->x2 - init->x1) * 300;
	init->height = (init->y2 - init->y1) * 300;;
	init->iter = 30;
	init->col = 0;
	init->julx = 0;
	init->july = 0;
	init->fixjul = 1;
	init->img = ft_init_img(init);
}

int				main(int ac, char **av)
{
	t_env	*init;

	if (ac == 2)
	{
		if (ft_strequ(av[1], "mandelbrot") || ft_strequ(av[1], "julia") ||
		ft_strequ(av[1], "other"))
		{
			if (!(init = (t_env *)malloc(sizeof(*init))))
				error();
			init->mlx = mlx_init();
			ft_initenv(init, av[1]);
			init->win = mlx_new_window(init->mlx, init->width, init->height, "Fractol");
			draw(init);
			mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
			mlx_hook(init->win, 2, 0, key_hook, init);
			if (ft_strequ(av[1], "julia"))
				mlx_hook(init->win, 6, 0, mouse_julia, init);
			mlx_hook(init->win, 4, 0, mouse_hook, init);
			mlx_expose_hook(init->win, expose_hook, init);
			mlx_loop(init->mlx);
		}
	}
	else
		error();
	return (0);
}
