/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mouse_hook_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:06:32 by cballest          #+#    #+#             */
/*   Updated: 2018/05/02 19:13:32 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	main_mouse_hook_10(int k, int x, int y, t_control *l)
{
	if ((k == 1 && (x >= (W + 45) + 75 && x <= (W + 45) + 150)
		&& (y >= 750 && y <= 1000)) && l->coef->menu_state == 3)
	{
		if (!l->coef->status)
		{
			obj_realloc(l);
		}
		ft_putnbr(l->coef->cur);
//		menu_hook_add(k, l);
		if (l->coef->status)
			l->coef->cur = l->coef->id_swap;
		l->coef->menu_state = 0;
		trace_info(l);
	}
	if ((k == 1 && (x >= (W + 45) + 150 && x <= (W + 45) + 250)
		&& (y >= 750 && y <= 1000)) && l->coef->menu_state == 3)
	{
//		menu_hook_cancel(k, l);
		l->coef->menu_state = 0;
		if (l->coef->status)
			l->coef->cur = l->coef->id_swap;
		else
			l->coef->cur += 1;
		trace_info(l);
	}
}

void	main_mouse_hook_9(int k, int x, int y, t_control *l)
{
	if ((x >= W + 45 && x <= W + 350) && (y >= 330 && y <= 360)
		&& l->coef->menu_state == 3)
	{
		menu_hook_stry(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 370 && y <= 400)
		&& l->coef->menu_state == 3)
	{
		menu_hook_strz(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 690 && y <= 720)
		&& l->coef->menu_state == 3)
	{
		menu_hook_axe(k, x, y, l);
		trace_info_3(l, 1);
	}
//	if ((k == 1 && (x >= (W + 45) + 0 && x <= (W + 45) + 75)
//		&& (y >= 750 && y <= 1000)) && l->coef->menu_state == 3)
//		menu_hook_update(k, l);
}

void	main_mouse_hook_8(int k, int x, int y, t_control *l)
{
	if ((x >= W + 45 && x <= W + 350) && (y >= 150 && y <= 180)
		&& l->coef->menu_state == 3)
	{
		menu_hook_rotx(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 190 && y <= 220)
		&& l->coef->menu_state == 3)
	{
		menu_hook_roty(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 230 && y <= 260)
		&& l->coef->menu_state == 3)
	{
		menu_hook_rotz(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 290 && y <= 320)
		&& l->coef->menu_state == 3)
	{
		menu_hook_strx(k, x, y, l);
		trace_info_3(l, 1);
	}
}

void	main_mouse_hook_7(int k, int x, int y, t_control *l)
{
	if ((x >= W + 45 && x <= W + 350) && (y >= 570 && y <= 600)
		&& l->coef->menu_state == 3)
	{
		menu_hook_b(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 10 && y <= 40)
		&& l->coef->menu_state == 3)
	{
		menu_hook_posx(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 50 && y <= 75)
		&& l->coef->menu_state == 3)
	{
		menu_hook_posy(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 90 && y <= 115)
		&& l->coef->menu_state == 3)
	{
		menu_hook_posz(k, x, y, l);
		trace_info_3(l, 1);
	}
}

void	main_mouse_hook_6(int k, int x, int y, t_control *l)
{
	if ((x >= W + 45 && x <= W + 350) && (y >= 430 && y <= 460)
		&& l->coef->menu_state == 3)
	{
		menu_hook_rad(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 630 && y <= 660)
		&& l->coef->menu_state == 3)
	{
		menu_hook_type(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 490 && y <= 520)
		&& l->coef->menu_state == 3)
	{
		menu_hook_r(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 530 && y <= 560)
		&& l->coef->menu_state == 3)
	{
		menu_hook_g(k, x, y, l);
		trace_info_3(l, 1);
	}
}
