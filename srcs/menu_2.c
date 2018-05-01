/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:26:13 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 17:26:21 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	hook_not_5(t_control *l, void *img, int *w, int *h)
{
	img = mlx_xpm_file_to_image(l->coef->mlx, \
		"ressources/img/menu_0/add_obj_hover.XPM", w, h);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 400);
	l->coef->is_on_button = 1;
}

void	hook_not_4(t_control *l, void *img, int *w, int *h)
{
	t_img	bl;

	bl.img = mlx_new_image(l->coef->mlx, 350, 35);
	if (l->coef->wtf == 0)
		img = mlx_xpm_file_to_image(l->coef->mlx, \
			"ressources/img/menu_1/wtf/hover_0.XPM", w, h);
	else
	{
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, bl.img, W, 165);
		img = mlx_xpm_file_to_image(l->coef->mlx, \
			"ressources/img/menu_1/wtf/hover_1.XPM", w, h);
	}
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 165);
	l->coef->is_on_button = 1;
}

void	hook_not_3(t_control *l, void *img, int *w, int *h)
{
	t_img	bl;

	bl.img = mlx_new_image(l->coef->mlx, 350, 35);
	if (l->coef->cartoon == 0)
		img = mlx_xpm_file_to_image(l->coef->mlx, \
			"ressources/img/menu_1/cartoon/hover_0.XPM", w, h);
	else
	{
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, bl.img, W, 130);
		img = mlx_xpm_file_to_image(l->coef->mlx, \
			"ressources/img/menu_1/cartoon/hover_1.XPM", w, h);
	}
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 130);
	l->coef->is_on_button = 1;
}

void	hook_not_2(t_control *l, void *img, int *w, int *h)
{
	t_img	bl;

	bl.img = mlx_new_image(l->coef->mlx, 350, 35);
	if (l->coef->sepia == 0)
		img = mlx_xpm_file_to_image(l->coef->mlx, \
			"ressources/img/menu_1/sepia/hover_0.XPM", w, h);
	else
	{
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, bl.img, W, 95);
		img = mlx_xpm_file_to_image(l->coef->mlx, \
			"ressources/img/menu_1/sepia/hover_1.XPM", w, h);
	}
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 95);
	l->coef->is_on_button = 1;
}

void	hook_not_1(t_control *l, void *img, int *w, int *h)
{
	t_img	bl;

	bl.img = mlx_new_image(l->coef->mlx, 350, 35);
	if (l->coef->negatif == 0)
		img = mlx_xpm_file_to_image(l->coef->mlx, \
			"ressources/img/menu_1/neg/hover_0.XPM", w, h);
	else
	{
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, bl.img, W, 60);
		img = mlx_xpm_file_to_image(l->coef->mlx, \
			"ressources/img/menu_1/neg/hover_1.XPM", w, h);
	}
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 60);
	l->coef->is_on_button = 1;
}
