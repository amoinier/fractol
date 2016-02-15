/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 18:15:29 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/15 21:03:14 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static	void	zoomless(t_env *init, double scal[2])
{
	init->x1 = init->x1 - (scal[0] * 0.4);
	init->x2 = init->x2 + (scal[0] * 0.4);
	init->y1 = init->y1 - (scal[1] * 0.4);
	init->y2 = init->y2 + (scal[1] * 0.4);
}

void			zoom(t_env *init, int button, int x, int y)
{
	double tmp;
	double scal[2];

	init->cr = x / (init->width / (init->x2 - init->x1)) + init->x1;
	init->ci = y / (init->height / (init->y2 - init->y1)) + init->y1;
	scal[0] = (init->x2 - init->x1);
	scal[1] = (init->y2 - init->y1);
	if (button == 5 || button == 116)
	{
		tmp = init->x1;
		init->x1 = (init->cr + (init->x2 + init->x1) / 2) / 2 - (scal[0] * 0.4);
		init->x2 = (init->cr + (init->x2 + tmp) / 2) / 2 + (scal[0] * 0.4);
		tmp = init->y1;
		init->y1 = (init->ci + (init->y2 + init->y1) / 2) / 2 - (scal[1] * 0.4);
		init->y2 = (init->ci + (init->y2 + tmp) / 2) / 2 + (scal[1] * 0.4);
		init->zoom *= 1.27;
	}
	if (button == 4 || button == 121)
	{
		zoomless(init, scal);
		init->zoom /= 1.27;
	}
}

void			keypadcode_col(int keycode, t_env *init)
{
	if (keycode == 82)
		init->col = 0xfff0ff;
	if (keycode == 83)
		init->col = 777777;
	if (keycode == 84)
		init->col = (777777) / 1000;
	if (keycode == 85)
		init->col = 9999999;
	if (keycode == 86)
		init->col = 7668190;
	if (keycode == 87)
		init->col = 46401678;
	if (keycode == 88)
		init->col = 137517911;
	if (keycode == 67)
		init->col = rand() % 23800176;
	if (keycode == 125)
		init->movey -= 1.0 / init->zoom;
	if (keycode == 126)
		init->movey += 1.0 / init->zoom;
	if (keycode == 123)
		init->movex += 1.0 / init->zoom;
	if (keycode == 124)
		init->movex -= 1.0 / init->zoom;
}
