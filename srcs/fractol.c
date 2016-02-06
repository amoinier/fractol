/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:09:53 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/06 17:40:26 by amoinier         ###   ########.fr       */
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
	init->iter = 100;
	init->fract = av;
	init->zoom_x = init->width / (0.6 - (-2.1));
	init->zoom_y = init->height / (1.2 - -(1.2));
	init->img = ft_init_img(init);
}

int				main(int ac, char **av)
{
	t_env	*init;

	if (ac == 2)
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
