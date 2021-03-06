/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractalbis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 18:36:26 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/16 16:15:59 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	draw_burning(t_env *init, int x, int y)
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
		init->zi = 2 * fabs(init->zi * tmp) + init->ci;
		i++;
	}
	if (i == init->iter)
		pixel_put_image(init, x, y, 0xffffff);
	else
		pixel_put_image(init, x, y, i * init->col);
}

void	draw_douady(t_env *init, int x, int y)
{
	double	tmp;
	double	i;
	double	xscal;
	double	yscal;

	xscal = (init->width / (init->x2 - init->x1));
	yscal = (init->height / (init->y2 - init->y1));
	init->zr = x / xscal + init->x1 + init->movex;
	init->zi = y / yscal + init->y1 + init->movey;
	init->cr = -0.12;
	init->ci = 0.75;
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
