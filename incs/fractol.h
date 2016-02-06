/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:10:31 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/06 18:24:48 by amoinier         ###   ########.fr       */
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
	float 		zoom_x;
	float		zoom_y;
	float		movex;
	float		movey;

    t_img       *img;

	float		x1;
	float		x2;
	float		y1;
	float		y2;
	int			iter;
	char		*fract;
}				t_env;

int				mouse_hook(int button, int x, int y, t_env *init);
int				key_hook(int keycode, t_env *init);
int				expose_hook(t_env *init);

void			pixel_put_image(t_env *init, int x, int y, int color);
void			ft_clear_img(t_env *init);

void    		draw(t_env *init);

int             error(void);

#endif
