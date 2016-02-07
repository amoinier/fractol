/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:51:29 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/06 19:25:47 by amoinier         ###   ########.fr       */
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

    cr = x / (init->zoom_x) + init->x1 + init->movex;
    ci = y / (init->zoom_y) + init->y1 + init->movey;
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
