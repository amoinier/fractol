/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:12:54 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/12 19:43:41 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	ft_str_win(init);
	return (0);
}

int				mouse_julia(int x, int y, t_env *init)
{
	if (init->fixjul == 0)
	{
		ft_clear_img(init);
		init->julx = (double)x / (double)(init->width / 2) - 1;
		init->july = (double)y / (double)(init->height / 2) - 1;
		draw(init);
		mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
		ft_str_win(init);
	}
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
		keypadcode_col(keycode, init);
	zoom(init, keycode, init->width / 2, init->height / 2);
	if (init->iter > 0)
		if (keycode == 78)
			init->iter -= 10;
	if (keycode == 69)
		init->iter += 10;
	draw(init);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	ft_str_win(init);
	return (0);
}

int				expose_hook(t_env *init)
{
	draw(init);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	ft_str_win(init);
	return (0);
}
