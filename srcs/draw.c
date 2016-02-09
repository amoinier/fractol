/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:51:29 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/09 17:52:40 by amoinier         ###   ########.fr       */
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

    cr = x / (init->zoomx / (init->x2 - init->x1)) + init->x1;
    ci = y / (init->zoomy / (init->y2 - init->y1)) + init->y1;
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
    int i;
    double  rx;
    double  ry;

    i = 0;
    rx = x / (init->zoomx / (init->x2 - init->x1)) + init->x1;
    ry = y / (init->zoomy / (init->y2 - init->y1)) + init->y1;;
    while (rx < 2 && i < init->iter)
    {
        rx = (8/9) * rx + ry;
        i++;
    }
    if (i == init->iter)
        pixel_put_image(init, x, y, 0xffffff);
    else
        pixel_put_image(init, x, y, i * init->col);
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
