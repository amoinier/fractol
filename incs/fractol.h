/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:10:31 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/12 18:38:03 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <mlx.h>

typedef	struct	s_img
{
	void		*img;
	char		*cimg;
	int			bpp;
	int			sizel;
	int			endn;
}				t_img;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			zoom;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	double 		zoomy;
	double 		zoomx;

    t_img       *img;

	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		col;
	double		julx;
	double		july;
	double		movex;
	double		movey;
	int			fixjul;
	int			iter;
	char		*fract;
}				t_env;

int				mouse_hook(int button, int x, int y, t_env *init);
int				mouse_julia(int x, int y, t_env *init);
int				key_hook(int keycode, t_env *init);
int				expose_hook(t_env *init);
void			keypadcode_col(int keycode, t_env *init);
void			zoom(t_env *init, int button, int x, int y);

void			draw_burning(t_env *init, int x, int y);
void			draw_fakenewton(t_env *init, int x, int y);

void			pixel_put_image(t_env *init, int x, int y, int color);
void			ft_clear_img(t_env *init);

void    		draw(t_env *init);

int             error(void);

#endif
