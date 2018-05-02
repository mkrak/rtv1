/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_hook_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:49:02 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 15:49:12 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	menu_hook_type(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 630 && y <= 660)
		&& k == 1)
		l->coef->type -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 630 && y <= 660)
		&& k == 1)
		l->coef->type -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 630 && y <= 660)
		&& k == 1)
		l->coef->type -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 630 && y <= 660)
		&& k == 1)
		l->coef->type += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 630 && y <= 660)
		&& k == 1)
		l->coef->type += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 630 && y <= 660)
		&& k == 1)
		l->coef->type += 100;
}

void	menu_hook_axe(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 690 && y <= 720)
		&& k == 1
		&& l->coef->axe > 'x')
		l->coef->axe--;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 690 && y <= 720)
		&& k == 1
		&& l->coef->axe < 'z')
		l->coef->axe++;
}

void	menu_hook_rad(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 430 && y <= 460)
		&& k == 1)
		l->coef->rad -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 430 && y <= 460)
		&& k == 1)
		l->coef->rad -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 430 && y <= 460)
		&& k == 1)
		l->coef->rad -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 430 && y <= 460)
		&& k == 1)
		l->coef->rad += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 430 && y <= 460)
		&& k == 1)
		l->coef->rad += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 430 && y <= 460)
		&& k == 1)
		l->coef->rad += 100;
}

void	menu_hook_r(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 490 && y <= 520)
		&& k == 1)
		l->coef->r -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 490 && y <= 520)
		&& k == 1)
		l->coef->r -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 490 && y <= 520)
		&& k == 1)
		l->coef->r -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 490 && y <= 520)
		&& k == 1)
		l->coef->r += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 490 && y <= 520)
		&& k == 1)
		l->coef->r += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 490 && y <= 520)
		&& k == 1)
		l->coef->r += 100;
}

void	menu_hook_g(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 530 && y <= 560)
		&& k == 1)
		l->coef->g -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 530 && y <= 560)
		&& k == 1)
		l->coef->g -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 530 && y <= 560)
		&& k == 1)
		l->coef->g -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 530 && y <= 560)
		&& k == 1)
		l->coef->g += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 530 && y <= 560)
		&& k == 1)
		l->coef->g += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 530 && y <= 560)
		&& k == 1)
		l->coef->g += 100;
}