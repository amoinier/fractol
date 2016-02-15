/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:02:13 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/15 21:11:20 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	ft_str_win(t_env *init)
{
	mlx_string_put(init->mlx, init->win, 10, 5, 0xFF0000, "FRACTOL");
	mlx_string_put(init->mlx, init->win, 10, 25, 0xffffff, "Fractal :");
	mlx_string_put(init->mlx, init->win, 105, 25, 0xffffff, init->fract);
	mlx_string_put(init->mlx, init->win, 10, 45, 0xffffff, "Zoom :");
	mlx_string_put(init->mlx, init->win, 75, 45, 0xffffff,
		ft_itoa(sqrt(init->zoom) / 1.27));
	mlx_string_put(init->mlx, init->win, 10, 65, 0xffffff, "Iteration :");
	mlx_string_put(init->mlx, init->win, 125, 65, 0xffffff,
		ft_itoa(init->iter));
	if (ft_strequ(init->fract, "julia"))
	{
		mlx_string_put(init->mlx, init->win, 10, 145, 0xffffff, "Julia Fix :");
		mlx_string_put(init->mlx, init->win, 125, 145, 0xffffff,
			ft_itoa(init->fixjul));
		mlx_string_put(init->mlx, init->win, 10, 85, 0xffffff,
			"JuliaX (* 1000):");
		mlx_string_put(init->mlx, init->win, 190, 85, 0xffffff,
			ft_itoa(init->julx * 1000));
		mlx_string_put(init->mlx, init->win, 10, 105, 0xffffff,
			"JuliaY (* 1000):");
		mlx_string_put(init->mlx, init->win, 190, 105, 0xffffff,
			ft_itoa(init->july * 1000));
	}
	mlx_string_put(init->mlx, init->win, 10, init->height - 50, 0xffffff,
		"Press ESC to quit");
}
