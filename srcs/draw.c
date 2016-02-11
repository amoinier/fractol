/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:51:29 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/11 12:45:48 by amoinier         ###   ########.fr       */
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

void    draw_sierp(t_env *init, double x, double y)
{
    double i;
    double j;
    double k;
    double sx;
    double sy;

    i = 0;
    x = init->x1 - init->x2;
    y = init->y1 - init->y2;
    while (i <= init->iter / 10)
    {
        j = 1;
        sx = (init->width / pow(3, i));
        sy = (init->height / pow(3, i));
        while (j * sx <= init->width)
        {
            k = 1;
            if (x >= sx * j && x <= sx * (2 + j - 1) && y >= sy && y <= sy * 2)
            {
                pixel_put_image(init, x, y, i * init->col);
                return ;
            }
            else if (x >= sx && x <= sx * 2 && y >= sy * j && y <= sy * (2 + j - 1))
            {
                pixel_put_image(init, x, y, i * init->col);
                return ;
            }
            else if (x >= sx * j && x <= sx * (2 + j - 1) && y <= init->height - sy && y >= init->height - (sy * 2))
            {
                pixel_put_image(init, x, y, i * init->col);
                return ;
            }
            else if (x <= init->width - sx && x >= init->width - sx * 2 && y >= sy * j && y <= sy * (2 + j - 1))
            {
                pixel_put_image(init, x, y, i * init->col);
                return ;
            }
            else
            {
                while (k * sx <= init->width)
                {
                    if (x >= sx * k && x <= sx * (2 + k - 1) && y >= sy * j && y <= sy * (2 + j - 1))
                    {
                        pixel_put_image(init, x, y, i * init->col);
                        return ;
                    }
                    k = k + 3;
                }
            }
            j = j + 3;
        }
        i++;
    }
}

void    draw(t_env *init)
{
    int i;
    int j;

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
            if (ft_strequ(init->fract, "other"))
                draw_sierp(init, i, j);
            j++;
        }
        i++;
    }
}
