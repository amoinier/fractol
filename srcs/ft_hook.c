/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:12:54 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/06 19:01:49 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_hook(int button, int x, int y, t_env *init)
{
	x *= 1;
	y *= 1;
	ft_clear_img(init);
	if (button == 5)
	{
		init->zoom_x += 50;
		init->zoom_y += 50;
	}
	if (button == 4)
	{
		init->zoom_x -= 50;
		init->zoom_y -= 50;
	}
	draw(init);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	return (0);
}

int				key_hook(int keycode, t_env *init)
{
	ft_clear_img(init);
	if (keycode == 53)
	{
		mlx_destroy_image(init->mlx, init->img->img);
		mlx_destroy_window(init->mlx, init->win);
		exit(0);
	}
	if (keycode == 69)
		init->iter += 1;
	if (keycode == 78)
		init->iter -= 1;
	if (keycode == 123)
		init->x1 -= 0.1;
	if (keycode == 124)
		init->x1 += 0.1;
	if (keycode == 125)
		init->y1 -= 0.1;
	if (keycode == 126)
		init->y1 += 0.1;
	draw(init);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	return (0);
}

int				expose_hook(t_env *init)
{
	init->height *= 1;
	return (0);
}
