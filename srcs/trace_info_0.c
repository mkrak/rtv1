/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_info_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:06:24 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 14:06:28 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	trace_info_0_3(t_control *c, int *h, int col)
{
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Pos X      (AU/AD): ", ft_itoa(c->coef->pos_x)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Pos Y      (AL/AR): ", ft_itoa(c->coef->pos_y)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Pos Z (CTRL/SHIFT): ", ft_itoa(c->coef->pos_z)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 20, col, \
			ft_strjoin("Rot X        (A/D): ", ft_itoa(c->coef->rot_x)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Rot Y        (W/S): ", ft_itoa(c->coef->rot_y)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Rot Z        (Q/E): ", ft_itoa(c->coef->rot_z)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 25, col, \
			"    Objets");
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Spheres           : ", ft_itoa(c->nb_obj)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Lumieres          : ", ft_itoa(c->nb_luz)));
}

void	trace_info_0_2(t_control *c, int *h, int col)
{
	float	f;
	char	s[255];

	f = (float)(c->coef->time - c->coef->prev_time) / 1000000;
	ftoa(f, s, 4);
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 25, col, \
			"    Scene");
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Width             : ", ft_itoa(W)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Height            : ", ft_itoa(H)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Aliasing     (+/-): ", ft_itoa(c->aliasing)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Anti-aliasing  (P): ", ft_itoa(c->antial)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Cartoon        (C): ", ft_itoa(c->coef->cartoon)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Negatif        (N): ", ft_itoa(c->coef->negatif)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("WTF            (X): ", ft_itoa(c->coef->wtf)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 15, col, \
			ft_strjoin("Time (in sec)     : ", s));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, *h += 25, col, \
			"    Camera");
}

void	trace_info_0_1(t_control *c)
{
	void	*bouton;
	int		width;
	int		height;

	bouton = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/menu_0/add_filter_norm.XPM", &width, &height);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton, W + 45, 360);
	bouton = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/menu_0/add_obj_norm.XPM", &width, &height);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton, W + 45, 400);
}

void	trace_info_0_0(t_control *c)
{
	t_rect	rect;

	rect.x = W + 45;
	rect.y = 25;
	rect.w = 275;
	rect.h = 320;
	rect.type = 0;
	rect.border = 1;
	rect.c.color = 0x0000b0b2;
	mlx_rect(rect, c->coef);
}

void	trace_info_0(t_control *c)
{
	t_img	img;
	int		h;
	int		col;

	h = 0;
	col = 0x00ffffff;
	img.img = mlx_new_image(c->coef->mlx, 350, H);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, img.img, W, 0);
	mlx_destroy_image(c->coef->mlx, img.img);
	trace_info_0_0(c);
	trace_info_0_1(c);
	trace_info_0_2(c, &h, col);
	trace_info_0_3(c, &h, col);
}
