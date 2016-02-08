/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:51:29 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/08 17:51:33 by amoinier         ###   ########.fr       */
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

    cr = x / init->zoomval + init->x1;
    ci = y / init->zoomval + init->y1;
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
    {
        pixel_put_image(init, x, y, 0xffffff);
    }
    else
        pixel_put_image(init, x, y, (i * 777777) / 1000);
}

void    draw(t_env *init)
{
    int i;
    int j;

    i = 0;
    while (i <= (init->x2 - init->x1) * init->zoomval)
    {
        j = 0;
        while (j <= (init->y2 - init->y1) * init->zoomval)
        {
            draw_mandel(init, i, j);
            j++;
        }
        i++;
    }
}
