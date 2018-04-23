/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:33:29 by cballest          #+#    #+#             */
/*   Updated: 2018/04/03 15:02:03 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	menu_hook_type(int k, int x, int y, t_control *l)
{
	if ((x >= 16 && x <= 48) && (y >= 350 && y <= 375) && k == 1)
		l->coef->type -= 100;
	if ((x >= 48 && x <= 80) && (y >= 350 && y <= 375) && k == 1)
		l->coef->type -= 10;
	if ((x >= 80 && x <= 112) && (y >= 350 && y <= 375) && k == 1)
		l->coef->type -= 1;
	if ((x >= 144 && x <= 176) && (y >= 350 && y <= 375) && k == 1)
		l->coef->type += 1;
	if ((x >= 176 && x <= 208) && (y >= 350 && y <= 375) && k == 1)
		l->coef->type += 10;
	if ((x >= 208 && x <= 240) && (y >= 350 && y <= 375) && k == 1)
		l->coef->type += 100;
}

void	menu_hook_rad(int k, int x, int y, t_control *l)
{
	if ((x >= 16 && x <= 48) && (y >= 150 && y <= 175) && k == 1)
		l->coef->rad -= 100;
	if ((x >= 48 && x <= 80) && (y >= 150 && y <= 175) && k == 1)
		l->coef->rad -= 10;
	if ((x >= 80 && x <= 112) && (y >= 150 && y <= 175) && k == 1)
		l->coef->rad -= 1;
	if ((x >= 144 && x <= 176) && (y >= 150 && y <= 175) && k == 1)
		l->coef->rad += 1;
	if ((x >= 176 && x <= 208) && (y >= 150 && y <= 175) && k == 1)
		l->coef->rad += 10;
	if ((x >= 208 && x <= 240) && (y >= 150 && y <= 175) && k == 1)
		l->coef->rad += 100;
}

void	menu_hook_r(int k, int x, int y, t_control *l)
{
	if ((x >= 16 && x <= 48) && (y >= 210 && y <= 235) && k == 1)
		l->coef->r -= 100;
	if ((x >= 48 && x <= 80) && (y >= 210 && y <= 235) && k == 1)
		l->coef->r -= 10;
	if ((x >= 80 && x <= 112) && (y >= 210 && y <= 235) && k == 1)
		l->coef->r -= 1;
	if ((x >= 144 && x <= 176) && (y >= 210 && y <= 235) && k == 1)
		l->coef->r += 1;
	if ((x >= 176 && x <= 208) && (y >= 210 && y <= 235) && k == 1)
		l->coef->r += 10;
	if ((x >= 208 && x <= 240) && (y >= 210 && y <= 235) && k == 1)
		l->coef->r += 100;
}

void	menu_hook_g(int k, int x, int y, t_control *l)
{
	if ((x >= 16 && x <= 48) && (y >= 250 && y <= 275) && k == 1)
		l->coef->g -= 100;
	if ((x >= 48 && x <= 80) && (y >= 250 && y <= 275) && k == 1)
		l->coef->g -= 10;
	if ((x >= 80 && x <= 112) && (y >= 250 && y <= 275) && k == 1)
		l->coef->g -= 1;
	if ((x >= 144 && x <= 176) && (y >= 250 && y <= 275) && k == 1)
		l->coef->g += 1;
	if ((x >= 176 && x <= 208) && (y >= 250 && y <= 275) && k == 1)
		l->coef->g += 10;
	if ((x >= 208 && x <= 240) && (y >= 250 && y <= 275) && k == 1)
		l->coef->g += 100;
}

void	menu_hook_b(int k, int x, int y, t_control *l)
{
	if ((x >= 16 && x <= 48) && (y >= 290 && y <= 315) && k == 1)
		l->coef->b -= 100;
	if ((x >= 48 && x <= 80) && (y >= 290 && y <= 315) && k == 1)
		l->coef->b -= 10;
	if ((x >= 80 && x <= 112) && (y >= 290 && y <= 315) && k == 1)
		l->coef->b -= 1;
	if ((x >= 144 && x <= 176) && (y >= 290 && y <= 315) && k == 1)
		l->coef->b += 1;
	if ((x >= 176 && x <= 208) && (y >= 290 && y <= 315) && k == 1)
		l->coef->b += 10;
	if ((x >= 208 && x <= 240) && (y >= 290 && y <= 315) && k == 1)
		l->coef->b += 100;
}

void	menu_hook_posx(int k, int x, int y, t_control *l)
{
	if ((x >= 16 && x <= 48) && (y >= 15 && y <= 40) && k == 1)
		l->coef->posx -= 100;
	if ((x >= 48 && x <= 80) && (y >= 15 && y <= 40) && k == 1)
		l->coef->posx -= 10;
	if ((x >= 80 && x <= 112) && (y >= 15 && y <= 40) && k == 1)
		l->coef->posx -= 1;
	if ((x >= 144 && x <= 176) && (y >= 15 && y <= 40) && k == 1)
		l->coef->posx += 1;
	if ((x >= 176 && x <= 208) && (y >= 15 && y <= 40) && k == 1)
		l->coef->posx += 10;
	if ((x >= 208 && x <= 240) && (y >= 15 && y <= 40) && k == 1)
		l->coef->posx += 100;
}

void	menu_hook_posy(int k, int x, int y, t_control *l)
{
	if ((x >= 16 && x <= 48) && (y >= 50 && y <= 75) && k == 1)
		l->coef->posy -= 100;
	if ((x >= 48 && x <= 80) && (y >= 50 && y <= 75) && k == 1)
		l->coef->posy -= 10;
	if ((x >= 80 && x <= 112) && (y >= 50 && y <= 75) && k == 1)
		l->coef->posy -= 1;
	if ((x >= 144 && x <= 176) && (y >= 50 && y <= 75) && k == 1)
		l->coef->posy += 1;
	if ((x >= 176 && x <= 208) && (y >= 50 && y <= 75) && k == 1)
		l->coef->posy += 10;
	if ((x >= 208 && x <= 240) && (y >= 50 && y <= 75) && k == 1)
		l->coef->posy += 100;
}

void	menu_hook_posz(int k, int x, int y, t_control *l)
{
	if ((x >= 16 && x <= 48) && (y >= 90 && y <= 115) && k == 1)
		l->coef->posz -= 100;
	if ((x >= 48 && x <= 80) && (y >= 90 && y <= 115) && k == 1)
		l->coef->posz -= 10;
	if ((x >= 80 && x <= 112) && (y >= 90 && y <= 115) && k == 1)
		l->coef->posz -= 1;
	if ((x >= 144 && x <= 176) && (y >= 90 && y <= 115) && k == 1)
		l->coef->posz += 1;
	if ((x >= 176 && x <= 208) && (y >= 90 && y <= 115) && k == 1)
		l->coef->posz += 10;
	if ((x >= 208 && x <= 240) && (y >= 90 && y <= 115) && k == 1)
		l->coef->posz += 100;
}

int		menu_hook_update(int k, t_control *l)
{
	l->obj[l->coef->cur].s = init_sphere(vec3(l->coef->posx, l->coef->posy, l->coef->posz) , l->coef->rad, vec3((float)l->coef->r / 100, (float)l->coef->g / 100, (float)l->coef->b / 100), l->coef->type);
	multithread(l);
	return (k);
}

int		menu_hook_add(int k, t_control *l)
{
		l->obj[l->coef->cur].s = init_sphere(vec3(l->coef->posx, l->coef->posy, l->coef->posz) , l->coef->rad, vec3((float)l->coef->r / 100, (float)l->coef->g / 100, (float)l->coef->b / 100), l->coef->type);
		if (l->coef->cur > l->coef->total)
			l->coef->total += 1;
		mlx_destroy_window(l->coef->mlx, l->coef->win_add);
		l->coef->cur = l->coef->total;
		multithread(l);
		l->coef->win_add = NULL;
		return (k);
}

int		menu_hook_cancel(int k, t_control *l)
{
		mlx_destroy_window(l->coef->mlx, l->coef->win_add);
		l->obj[l->coef->cur].s = l->coef->swap;
//		l->av = l->coef->cur;
		multithread(l);
		l->coef->win_add = NULL;
		return (k);
}

int		add_mouse_hook(int k, int x, int y, t_control *l)
{
	if (y >= 150 && y <= 175)
		menu_hook_rad(k, x, y, l);
	else if (y >= 350 && y <= 375)
		menu_hook_type(k, x, y, l);
	else if (y >= 210 && y <= 235)
		menu_hook_r(k, x, y, l);
	else if (y >= 250 && y <= 275)
		menu_hook_g(k, x, y, l);
	else if (y >= 290 && y <= 315)
		menu_hook_b(k, x, y, l);
	else if (y >= 15 && y <= 40)
		menu_hook_posx(k, x, y, l);
	else if (y >= 50 && y <= 75)
		menu_hook_posy(k, x, y, l);
	else if (y >= 90 && y <= 115)
		menu_hook_posz(k, x, y, l);
	else if (k == 1 && (x >= 0 && x <= 75) && (y >= 410 && y <= 750))
		menu_hook_update(k, l);
	else if (k == 1 && (x >= 75 && x <= 150) && (y >= 410 && y <= 750))
		return (menu_hook_add(k, l));
	else if (k == 1 && (x >= 150 && x <= 250) && (y >= 410 && y <= 750))
		return (menu_hook_cancel(k, l));
	menu_add(l, "SPHERE", 0);
	return (k);
}
