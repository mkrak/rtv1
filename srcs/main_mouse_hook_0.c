/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mouse_hook_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:06:18 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 17:06:30 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	main_mouse_hook_5(int k, int x, int y, t_control *l)
{
	if (k == 1 && (x >= W + 45 && x <= W + 350) && (y >= 100 &&
		y <= 175 && l->coef->menu_state == 2))
	{
		l->coef->shape = 1;
		l->coef->status = 0;
		l->coef->menu_state = 3;
		trace_info_3(l, 0);
	}
	if (k == 1 && (x >= W + 45 && x <= W + 350) && (y >= 185 &&
		y <= 260 && l->coef->menu_state == 2))
	{
		l->coef->shape = 2;
		l->coef->status = 0;
		l->coef->menu_state = 3;
		trace_info_3(l, 0);
	}
	if (k == 1 && (x >= W + 45 && x <= W + 350) && (y >= 270 &&
		y <= 345 && l->coef->menu_state == 2))
	{
		l->coef->shape = 3;
		l->coef->status = 0;
		l->coef->menu_state = 3;
		trace_info_3(l, 0);
	}
}

void	main_mouse_hook_4(int k, int x, int y, t_control *l)
{
	if (((x >= W + 45 && x <= W + 350) && (y >= 235 && y <= 255)) &&
		l && k == 1 && l->coef->menu_state == 1)
	{
		l->coef->sat = (x - (W + 45)) * 100 / 275;
		trace_info(l);
		multithread(l);
	}
	if (((x >= W + 45 && x <= W + 350) && (y >= 305 && y <= 325)) &&
		l && k == 1 && l->coef->menu_state == 1)
	{
		l->coef->lum = fmax(-254, (((x - (W + 45)) * 510 / 275) - 255));
		trace_info(l);
		multithread(l);
	}
	if (k == 1 && (x >= W + 45 && x <= W + 350) && (y >= 15 &&
		y <= 90 && l->coef->menu_state == 2))
	{
		l->coef->shape = 0;
		l->coef->status = 0;
		l->coef->menu_state = 3;
		trace_info_3(l, 0);
	}
}

void	main_mouse_hook_3(int k, int x, int y, t_control *l)
{
	if ((k == 1 && (x >= W + 45 && x <= W + 320) && (y >= 60 && y <= 95))
		&& l && l->coef->menu_state == 1)
	{
		if (l->coef->negatif == 0)
			l->coef->negatif = 1;
		else
			l->coef->negatif = 0;
		trace_info(l);
		multithread(l);
	}
	if ((k == 1 && (x >= W + 45 && x <= W + 320) && (y >= 165 && y <= 200))
		&& l && l->coef->menu_state == 1)
	{
		if (l->coef->wtf == 0)
			l->coef->wtf = 1;
		else
			l->coef->wtf = 0;
		trace_info(l);
		multithread(l);
	}
}

void	main_mouse_hook_2(int k, int x, int y, t_control *l)
{
	if ((k == 1 && (x >= W + 45 && x <= W + 320) && (y >= 95 && y <= 130))
		&& l && l->coef->menu_state == 1)
	{
		if (l->coef->sepia == 0)
			l->coef->sepia = 1;
		else
			l->coef->sepia = 0;
		trace_info(l);
		multithread(l);
	}
	if ((k == 1 && (x >= W + 45 && x <= W + 320) && (y >= 130 && y <= 165))
		&& l && l->coef->menu_state == 1)
	{
		if (l->coef->cartoon == 0)
			l->coef->cartoon = 1;
		else
			l->coef->cartoon = 0;
		trace_info(l);
		multithread(l);
	}
}

void	main_mouse_hook_1(int k, int x, int y, t_control *l)
{
	if ((k == 1 && (x >= W + 45 && x <= W + 75) && (y >= 25 && y <= 50))
		&& l && l->coef->menu_state == 1)
	{
		l->coef->menu_state = 0;
		trace_info(l);
	}
	if ((k == 1 && (x >= W + 45 && x <= W + 320) && (y >= 360 && y <= 395))
		&& l && l->coef->menu_state == 0)
	{
		l->coef->menu_state = 1;
		trace_info(l);
	}
	// if ((k == 1 && (x >= W + 45 && x <= W + 320) && (y >= 400 && y <= 435))
	// 	&& l && l->coef->menu_state == 0)
	// {
	// 	l->coef->menu_state = 2;
	// 	trace_info(l);
	// }
}
