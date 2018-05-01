/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_info_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:06:29 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 14:06:32 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	trace_info_1_2(t_img *bouton, t_control *c, int *n)
{
	if (c->coef->cartoon == 0)
		bouton->img = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/menu_1/cartoon/norm_0.XPM", &bouton->w, &bouton->h);
	else
		bouton->img = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/menu_1/cartoon/norm_1.XPM", &bouton->w, &bouton->h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton->img, W + 45, \
			*n += 35);
	if (c->coef->wtf == 0)
		bouton->img = mlx_xpm_file_to_image(c->coef->mlx, \
				"ressources/img/menu_1/wtf/norm_0.XPM", &bouton->w, &bouton->h);
	else
		bouton->img = mlx_xpm_file_to_image(c->coef->mlx, \
				"ressources/img/menu_1/wtf/norm_1.XPM", &bouton->w, &bouton->h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton->img, W + 45, \
			*n += 35);
	bouton->img = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/menu_1/sat/img.XPM", &bouton->w, &bouton->h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton->img, W + 45, \
			*n += 35);
}

void	trace_info_1_1(t_img *bouton, t_control *c, int *n)
{
	bouton->img = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/menu_1/title.XPM", &bouton->w, &bouton->h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton->img, W + 45,\
			*n + 25);
	bouton->img = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/menu_1/back.XPM", &bouton->w, &bouton->h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton->img, \
			W + 45, *n += 25);
	if (c->coef->negatif == 0)
		bouton->img = mlx_xpm_file_to_image(c->coef->mlx, \
				"ressources/img/menu_1/neg/norm_0.XPM", &bouton->w, &bouton->h);
	else
		bouton->img = mlx_xpm_file_to_image(c->coef->mlx, \
				"ressources/img/menu_1/neg/norm_1.XPM", &bouton->w, &bouton->h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton->img, W + 45, \
			*n += 35);
	if (c->coef->sepia == 0)
		bouton->img = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/menu_1/sepia/norm_0.XPM", &bouton->w, &bouton->h);
	else
		bouton->img = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/menu_1/sepia/norm_1.XPM", &bouton->w, &bouton->h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton->img, W + 45, \
			*n += 35);
}

void	trace_info_1_0(t_scrol *lum, t_scrol *scroll)
{
	lum->bar.x = W + 45;
	lum->bar.w = 275;
	lum->bar.h = 2;
	lum->bar.type = 0;
	lum->bar.border = 1;
	lum->c1.color = 0x0000b0b2;
	lum->c2.color = 0x00002324;
	lum->value = 15;
	lum->id = 1;
	scroll->bar.x = W + 45;
	scroll->bar.w = 275;
	scroll->bar.h = 2;
	scroll->bar.type = 0;
	scroll->bar.border = 1;
	scroll->c1.color = 0x0000b0b2;
	scroll->c2.color = 0x00002324;
	scroll->value = 35;
	scroll->id = 0;
}

void	trace_info_1(t_control *c)
{
	t_img		bouton;
	t_img		img;
	t_scrol		lum;
	t_scrol		scroll;
	int			n;

	n = 0;
	trace_info_1_0(&lum, &scroll);
	img.img = mlx_new_image(c->coef->mlx, 350, H);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, img.img, W, 0);
	mlx_destroy_image(c->coef->mlx, img.img);
	trace_info_1_1(&bouton, c, &n);
	trace_info_1_2(&bouton, c, &n);
	scroll.bar.y = n += 45;
	mlx_scroll_bar(scroll, c->coef);
	bouton.img = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/menu_1/lum/img.XPM", &bouton.w, &bouton.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton.img, W + 45, \
			n += 25);
	lum.bar.y = n += 45;
	mlx_scroll_bar(lum, c->coef);
}
