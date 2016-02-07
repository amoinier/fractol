/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:09:53 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/07 18:10:12 by amoinier         ###   ########.fr       */
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
	init->width = 1000;
	init->height = 1000;
	init->iter = 50;
	init->fract = av;
	init->x1 = -2.1;
	init->x2 = 0.6;
	init->y1 = -1.2;
	init->y2 = 1.2;
	init->movex = init->x1;
	init->movey = init->y1;
	init->zoom = 1;
	init->zoom_x = init->width / (init->x2 - init->x1);
	init->zoom_y = init->height / (init->y2 - init->y1);
	init->img = ft_init_img(init);
}

int				main(int ac, char **av)
{
	t_env	*init;

	if (ac == 2 && ft_strequ(av[1], "mandelbrot"))
	{
		if (!(init = (t_env *)malloc(sizeof(*init))))
			error();
		init->mlx = mlx_init();
		ft_initenv(init, av[1]);
		init->win = mlx_new_window(init->mlx, init->width, init->height, "Fractol");
		draw(init);
		mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
		mlx_hook(init->win, 2, 0, key_hook, init);
		mlx_mouse_hook(init->win, mouse_hook, init);
		mlx_expose_hook(init->win, expose_hook, init);
		mlx_loop(init->mlx);
	}
	else
		error();
	return (0);
}
