/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:51:29 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/16 17:09:15 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_mandel(t_env *init, int x, int y)
{
	double	tmp;
	double	i;
	double	xscal;
	double	yscal;

	xscal = (init->width / (init->x2 - init->x1));
	yscal = (init->height / (init->y2 - init->y1));
	init->cr = (x / xscal + init->x1 + init->movex) * 1.5;
	init->ci = (y / yscal + init->y1 + init->movey) * 1.5;
	init->zr = 0;
	init->zi = 0;
	i = 0;
	while (init->zr * init->zr + init->zi * init->zi < 4 && i < init->iter)
	{
		tmp = init->zr;
		init->zr = init->zr * init->zr - init->zi * init->zi + init->cr;
		init->zi = 2 * init->zi * tmp + init->ci;
		i++;
	}
	if (i == init->iter)
		pixel_put_image(init, x, y, 0xffffff);
	else
		pixel_put_image(init, x, y, i * init->col);
}

void		draw_julia(t_env *init, int x, int y)
{
	double	tmp;
	int		i;
	double	xscal;
	double	yscal;

	xscal = (init->width / (init->x2 - init->x1));
	yscal = (init->height / (init->y2 - init->y1));
	init->zr = (x / xscal + init->x1 + init->movex) * 2;
	init->zi = (y / yscal + init->y1 + init->movey) * 2;
	init->cr = init->julx;
	init->ci = init->july;
	i = 0;
	while (init->zr * init->zr + init->zi * init->zi < 4 && i < init->iter)
	{
		tmp = init->zr;
		init->zr = init->zr * init->zr - init->zi * init->zi + init->cr;
		init->zi = 2 * init->zi * tmp + init->ci;
		i++;
	}
	if (i == init->iter)
		pixel_put_image(init, x, y, 0xffffff);
	else
		pixel_put_image(init, x, y, i * init->col);
}

static	int	sierp(t_env *init, int i, double xy[2], double s[2])
{
	int	k;
	int	j;

	j = 1;
	while (j * s[0] <= init->width)
	{
		k = 1;
		while (k * s[0] <= init->width)
		{
			if (init->zr >= s[0] * k && init->zr <= s[0] * (2 + k - 1)
			&& init->zi >= s[1] * j && init->zi <= s[1] * (2 + j - 1))
			{
				pixel_put_image(init, xy[0], xy[1], i * init->col);
				return (1);
			}
			k = k + 3;
		}
		j = j + 3;
	}
	return (0);
}

void		draw_sierp(t_env *init, double x, double y)
{
	int		i;
	double	s[2];
	double	xy[2];
	double	xscal;
	double	yscal;

	i = 0;
	xscal = (init->width / (init->x2 - init->x1));
	yscal = (init->height / (init->y2 - init->y1));
	init->zr = (x / xscal + init->x1 + init->movex) * 600;
	init->zi = (y / yscal + init->y1 + init->movey) * 600;
	s[0] = init->width * 3;
	s[1] = init->height * 3;
	while (i <= init->iter / 10)
	{
		s[0] = s[0] / 3;
		s[1] = s[1] / 3;
		xy[0] = x;
		xy[1] = y;
		if (sierp(init, i, xy, s) == 1)
			return ;
		i++;
	}
}

void		draw(t_env *init)
{
	int	i;
	int	j;

	j = 0;
	while (j <= init->height)
	{
		i = 0;
		while (i <= init->width)
		{
			if (ft_strequ(init->fract, "julia"))
				draw_julia(init, i, j);
			if (ft_strequ(init->fract, "mandelbrot"))
				draw_mandel(init, i, j);
			if (ft_strequ(init->fract, "douady"))
				draw_douady(init, i, j);
			if (ft_strequ(init->fract, "burningship"))
				draw_burning(init, i, j);
			if (ft_strequ(init->fract, "sierpinski"))
				draw_sierp(init, i, j);
			i++;
		}
		j++;
	}
}
