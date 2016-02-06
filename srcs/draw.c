/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:51:29 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/06 17:41:37 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    draw_mandel(t_env *init, int x, int y)
{
    float cr;
    float ci;
    float zr;
    float zi;
    float tmp;
    float i;
    float x1;
    float x2;
    float y1;
    float y2;

    x1 = -2.1;
    x2 = 0.6;
    y1 = -1.2;
    y2 = 1.2;

    cr = x / (init->zoom_x) + x1;
    ci = y / (init->zoom_y) + y1;
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
        pixel_put_image(init, x, y, (i * 777777));
}

void    draw(t_env *init)
{
    int i;
    int j;

    i = 0;
    while (i < init->width)
    {
        j = 0;
        while (j < init->height)
        {
            draw_mandel(init, i, j);
            j++;
        }
        i++;
    }
}
