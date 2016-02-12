/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:51:29 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/12 17:35:54 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	draw_mandel(t_env *init, int x, int y)
{
   	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	tmp;
	double	i;

	cr = x / (init->zoomx / (init->x2 - init->x1)) + init->x1 + init->movex;
	ci = y / (init->zoomy / (init->y2 - init->y1)) + init->y1 + init->movey;
	zr = 0;
	zi = 0;
	i = 0;
	while (zr * zr + zi * zi < 4 && i < init->iter)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * zi * tmp + ci;
		i++;
	}
	if (i == init->iter)
		pixel_put_image(init, x, y, 0xffffff);
	else
		pixel_put_image(init, x, y, i * init->col);
}

void	draw_julia(t_env *init, int x, int y)
{
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = x / (init->zoomx / (init->x2 - init->x1)) + init->x1;
	zi = y / (init->zoomy / (init->y2 - init->y1)) + init->y1;
    zr *= 2;
    zi *= 2;
	cr = init->julx;
	ci = init->july;
	i = 0;
	while (zr * zr + zi * zi < 4 && i < init->iter)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * zi * tmp + ci;
		i++;
	}
	if (i == init->iter)
		pixel_put_image(init, x, y, 0xffffff);
	else
		pixel_put_image(init, x, y, i * init->col);
}

void	draw_sierp(t_env *init, double x, double y)
{
    // int i;
    // int zr;
    // int zi;
    //
    // i = init->iter / 10;
    // zr = x / (init->zoomx / (init->x2 - init->x1)) + init->x1 + 5;
	// zi = y / (init->zoomy / (init->y2 - init->y1)) + init->y1 + 5;
    // while (i >= 0)
    // {
    //     if (zr % 3 == 1 && zi % 3 == 1)
    //     {
    //         pixel_put_image(init, x, y, i * init->col);
    //         return ;
    //     }
    //     zi /= 9;
    //     zr /= 9;
    //     i--;
    // }
    // pixel_put_image(init, x, y, 0xffffff);

	double	i;
	double	j;
	double	k;
	double	sx;
	double	sy;
    double  zr;
    double  zi;

	i = 0;
    zr = x / (init->zoomx / (init->x2 - init->x1)) + init->x1 + init->movex;
    zi = y / (init->zoomy / (init->y2 - init->y1)) + init->y1 + init->movey;
    zr *= 600;
    zi *= 600;
	while (i <= init->iter / 10)
	{
		j = 1;
		sx = (init->width / pow(3, i));
		sy = (init->height / pow(3, i));
		while (j * sx <= init->width || j * sy <= init->height)
		{
            k = 1;
            while (k * sx <= init->width || k * sy <= init->height)
            {
                if (zr >= sx * k && zr <= sx * (2 + k - 1) && zi >= sy * j &&
                zi <= sy * (2 + j - 1))
                {
                    pixel_put_image(init, x, y, i * init->col);
                    return ;
                }
                k = k + 3;
            }
            j = j + 3;
        }
        i++;
    }
}

void	draw_fakenewton(t_env *init, int x, int y)
{
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	tmp;
	double	i;

	zr = x / (init->zoomx / (init->x2 - init->x1)) + init->x1 + init->movex;
	zi = y / (init->zoomy / (init->y2 - init->y1)) + init->y1 + init->movey;
	cr = -0.12;
	ci = 0.75;
	i = 0;
	while (zr * zr + zi * zi < 4 && i < init->iter)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * zi * tmp + ci;
		i++;
	}
	if (i == init->iter)
		pixel_put_image(init, x, y, 0xffffff);
	else
		pixel_put_image(init, x, y, i * init->col);
}

void	draw_burning(t_env *init, int x, int y)
{
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	tmp;
	double	i;

	cr = x / (init->zoomx / (init->x2 - init->x1)) + init->x1 + init->movex;
	ci = y / (init->zoomy / (init->y2 - init->y1)) + init->y1 + init->movey;
    cr *= 1.5;
    ci *= 1.5;
	zr = 0;
	zi = 0;
	i = 0;
	while (zr * zr + zi * zi < 4 && i < init->iter)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * fabs(zi * tmp) + ci;
		i++;
	}
	if (i == init->iter)
		pixel_put_image(init, x, y, 0xffffff);
	else
		pixel_put_image(init, x, y, i * init->col);
}

void	draw(t_env *init)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= init->width)
	{
		j = 0;
		while (j <= init->height)
		{
			if (ft_strequ(init->fract, "julia"))
				draw_julia(init, i, j);
			if (ft_strequ(init->fract, "mandelbrot"))
				draw_mandel(init, i, j);
			if (ft_strequ(init->fract, "fakenewton"))
				draw_fakenewton(init, i, j);
			if (ft_strequ(init->fract, "burning"))
				draw_burning(init, i, j);
			if (ft_strequ(init->fract, "other"))
				draw_sierp(init, i, j);
			j++;
		}
		i++;
	}
}
