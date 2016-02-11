/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:12:54 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/11 19:19:28 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_env *init, int button, int x, int y)
{
	double tmp;
	double newx;
	double newy;
	double scal[2];

	newx = x / (init->zoomx / (init->x2 - init->x1)) + init->x1;
	newy = y / (init->zoomy / (init->y2 - init->y1)) + init->y1;
	scal[0] = (init->x2 - init->x1);
	scal[1] = (init->y2 - init->y1);
	if (button == 5 || button == 116)
	{
		tmp = init->x1;
		init->x1 = (newx + (init->x2 + init->x1) / 2) / 2 - (scal[0] * 0.4);
		init->x2 = (newx + (init->x2 + tmp) / 2) / 2 + (scal[0] * 0.4);
		tmp = init->y1;
		init->y1 = (newy + (init->y2 + init->y1) / 2) / 2 - (scal[1] * 0.4);
		init->y2 = (newy + (init->y2 + tmp) / 2) / 2 + (scal[1] * 0.4);
		init->zoom *= 1.4;
	}
	if (button == 4 || button == 121)
	{
		init->x1 = init->x1 - (scal[0] * 0.52);
		init->x2 = init->x2 + (scal[0] * 0.52);
		init->y1 = init->y1 - (scal[1] * 0.52);
		init->y2 = init->y2 + (scal[1] * 0.52);
		init->zoom /= 1.52;
	}
}

int				mouse_hook(int button, int x, int y, t_env *init)
{
	ft_clear_img(init);
	zoom(init, button, x, y);
	if (button == 1 && init->fixjul == 0)
		init->fixjul = 1;
	else if (button == 1 && init->fixjul == 1)
		init->fixjul = 0;
	draw(init);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	return (0);
}

int		mouse_julia(int x, int y, t_env *init)
{
	if (init->fixjul == 1)
	{
		ft_clear_img(init);
		init->julx = (double)x / (double)(init->width / 2) - 1;
		init->july = (double)y / (double)(init->height / 2) - 1;
		draw(init);
		mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	}
	return (0);
}

static	void	keypadcode_col(int keycode, t_env *init)
{
	if (keycode == 82)
		init->col = 0xffffff + 33333333;
	if (keycode == 83)
		init->col = 777777;
	if (keycode == 84)
		init->col = (777777) / 1000;
	if (keycode == 85)
		init->col = 9999999;
	if (keycode == 86)
		init->col = 7668190;
	if (keycode == 87)
		init->col = 46401678;
	if (keycode == 88)
		init->col = 137517911;
	if (keycode == 67)
		init->col = rand() % 23800176;
	if (keycode == 125)
		init->movey -= 0.01 / init->zoom;
	if (keycode == 126)
		init->movey += 0.01 / init->zoom;
	if (keycode == 123)
		init->movex += 0.01 / init->zoom;
	if (keycode == 124)
		init->movex -= 0.01 / init->zoom;
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
	if (keycode > 66)
		keypadcode_col(keycode, init);
	zoom(init, keycode, init->width / 2, init->height / 2);
	if (init->iter > 0)
		if (keycode == 78)
			init->iter -= 10;
	if (keycode == 69)
		init->iter += 10;
	draw(init);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	return (0);
}

int				expose_hook(t_env *init)
{
	init->height *= 1;
	return (0);
}
