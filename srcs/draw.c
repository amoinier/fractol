/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:51:29 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/10 13:57:43 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>

void    draw_mandel(t_env *init, int x, int y)
{
    double cr;
    double ci;
    double zr;
    double zi;
    double tmp;
    double i;

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

void    draw_julia(t_env *init, int x, int y)
{
    double cr;
    double ci;
    double zr;
    double zi;
    double tmp;
    int i;

    zr = x / (init->zoomx / (init->x2 - init->x1)) + init->x1;
    zi = y / (init->zoomy / (init->y2 - init->y1)) + init->y1;
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

void    draw_sierp(t_env *init, int x, int y)
{
    double  xd;
    double yd;
    int i;
    int xx;
    int yy;

    x *= 1;
    y *= 1;
    xd = init->width;
    yd = init->height;
    i = 0;
    xx = 0;
    yy = 0;
    while (i < init->iter)
    {
        xd /= 2;
        yd /= 2;
        i++;
    }
}

void    draw(t_env *init)
{
    int i;
    int j;

    i = 0;
    while (i <= init->zoomx)
    {
        j = 0;
        while (j <= init->zoomy)
        {
            if (ft_strequ(init->fract, "julia"))
                draw_julia(init, i, j);
            if (ft_strequ(init->fract, "mandelbrot"))
                draw_mandel(init, i, j);
            if (ft_strequ(init->fract, "other"))
                draw_sierp(init, i, j);
            j++;
        }
        i++;
    }
}
