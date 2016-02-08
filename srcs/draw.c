/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:51:29 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/08 13:06:01 by amoinier         ###   ########.fr       */
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

    cr = x / (init->zoom_x) + init->x1;
    ci = y / (init->zoom_y) + init->y1;
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
/*
-2.1 = 500
-1.2 = 500

x 0.0024

?    = 750
?    = 750

init->movex = -2.1 >> 300 .... 500

*/
void    draw(t_env *init)
{
    int i;
    int j;

    i = 0;
    while (i <= init->width)
    {
        j = 0;
        while (j <= init->height)
        {
            draw_mandel(init, i, j);
            j++;
        }
        i++;
    }
}
