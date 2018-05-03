/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:47:33 by cballest          #+#    #+#             */
/*   Updated: 2018/05/03 13:24:38 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	hook_not_0(t_control *l, void *img, int *w, int *h)
{
	img = mlx_xpm_file_to_image(l->coef->mlx, \
		"ressources/img/menu_0/add_filter_hover.XPM", w, h);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 360);
	l->coef->is_on_button = 1;
}

int		main_mouse_hook_not_2(int x, int y, t_control *l)
{
	void	*img;
	int		w;
	int		h;

	img = NULL;
	if (((x >= W + 45 && x <= W + 320) && (y > 165 && y <= 198))
		&& l && l->coef->menu_state == 1)
		hook_not_4(l, img, &w, &h);
	else if (((x >= W + 45 && x <= W + 320) && (y >= 400 && y <= 435))
		&& l && l->coef->menu_state == 0)
		hook_not_5(l, img, &w, &h);
	else if (l->coef->is_on_button)
	{
		trace_info(l);
		l->coef->is_on_button = 0;
	}
	return (1);
}

int		main_mouse_hook_not(int x, int y, t_control *l)
{
	void	*img;
	int		w;
	int		h;

	img = NULL;
	if (((x >= W + 45 && x <= W + 320) && (y >= 360 && y <= 395)) &&
		l && l->coef->menu_state == 0)
		hook_not_0(l, img, &w, &h);
	else if (((x >= W + 45 && x <= W + 320) && (y > 60 && y <= 93))
		&& l && l->coef->menu_state == 1)
		hook_not_1(l, img, &w, &h);
	else if (((x >= W + 45 && x <= W + 320) && (y > 95 && y <= 128))
		&& l && l->coef->menu_state == 1)
		hook_not_2(l, img, &w, &h);
	else if (((x >= W + 45 && x <= W + 320) && (y > 130 && y <= 163))
		&& l && l->coef->menu_state == 1)
		hook_not_3(l, img, &w, &h);
	else
		return (main_mouse_hook_not_2(x, y, l));
	return (1);
}

int		main_mouse_hook(int k, int x, int y, t_control *l)
{
//	int		id;

//	if (k == 1 && ((x >= 0 && x <= W) && (y >= 0 && y <= H)) && l)
//	{
//		l->coef->status = 1;
//		l->coef->menu_state = 3;
//		id = rt_search(x, y, l);
//		l->coef->swap = get_obj(&l->obj, id);
//		l->coef->id_swap = l->coef->cur;
//		l->coef->cur = id;
//		trace_info_3(l, 2);
//	}
	main_mouse_hook_1(k, x, y, l);
	main_mouse_hook_2(k, x, y, l);
	main_mouse_hook_3(k, x, y, l);
	main_mouse_hook_4(k, x, y, l);
	main_mouse_hook_5(k, x, y, l);
	main_mouse_hook_6(k, x, y, l);
	main_mouse_hook_7(k, x, y, l);
	main_mouse_hook_8(k, x, y, l);
	main_mouse_hook_9(k, x, y, l);
	main_mouse_hook_10(k, x, y, l);
	return (k);
}
