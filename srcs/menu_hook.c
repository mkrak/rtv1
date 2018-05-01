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
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 630 && y <= 660) && k == 1)
		l->coef->type -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 630 && y <= 660) && k == 1)
		l->coef->type -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 630 && y <= 660) && k == 1)
		l->coef->type -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 630 && y <= 660) && k == 1)
		l->coef->type += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 630 && y <= 660) && k == 1)
		l->coef->type += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 630 && y <= 660) && k == 1)
		l->coef->type += 100;
}

void	menu_hook_axe(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 690 && y <= 720) && k == 1
		&& l->coef->axe > 'x')
		l->coef->axe--;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 690 && y <= 720) && k == 1
		&& l->coef->axe < 'z')
		l->coef->axe++;
}

void	menu_hook_rad(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 430 && y <= 460) && k == 1)
		l->coef->rad -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 430 && y <= 460) && k == 1)
		l->coef->rad -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 430 && y <= 460) && k == 1)
		l->coef->rad -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 430 && y <= 460) && k == 1)
		l->coef->rad += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 430 && y <= 460) && k == 1)
		l->coef->rad += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 430 && y <= 460) && k == 1)
		l->coef->rad += 100;
}

void	menu_hook_r(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 490 && y <= 520) && k == 1)
		l->coef->r -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 490 && y <= 520) && k == 1)
		l->coef->r -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 490 && y <= 520) && k == 1)
		l->coef->r -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 490 && y <= 520) && k == 1)
		l->coef->r += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 490 && y <= 520) && k == 1)
		l->coef->r += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 490 && y <= 520) && k == 1)
		l->coef->r += 100;
}

void	menu_hook_g(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 530 && y <= 560) && k == 1)
		l->coef->g -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 530 && y <= 560) && k == 1)
		l->coef->g -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 530 && y <= 560) && k == 1)
		l->coef->g -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 530 && y <= 560) && k == 1)
		l->coef->g += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 530 && y <= 560) && k == 1)
		l->coef->g += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 530 && y <= 560) && k == 1)
		l->coef->g += 100;
}

void	menu_hook_b(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 570 && y <= 600) && k == 1)
		l->coef->b -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 570 && y <= 600) && k == 1)
		l->coef->b -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 570 && y <= 600) && k == 1)
		l->coef->b -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 570 && y <= 600) && k == 1)
		l->coef->b += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 570 && y <= 600) && k == 1)
		l->coef->b += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 570 && y <= 600) && k == 1)
		l->coef->b += 100;
}

void	menu_hook_posx(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 10 && y <= 40) && k == 1)
		l->coef->posx -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 10 && y <= 40) && k == 1)
		l->coef->posx -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 10 && y <= 40) && k == 1)
		l->coef->posx -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 10 && y <= 40) && k == 1)
		l->coef->posx += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 10 && y <= 40) && k == 1)
		l->coef->posx += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 10 && y <= 40) && k == 1)
		l->coef->posx += 100;
}

void	menu_hook_posy(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 50 && y <= 75) && k == 1)
		l->coef->posy -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 50 && y <= 75) && k == 1)
		l->coef->posy -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 50 && y <= 75) && k == 1)
		l->coef->posy -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 50 && y <= 75) && k == 1)
		l->coef->posy += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 50 && y <= 75) && k == 1)
		l->coef->posy += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 50 && y <= 75) && k == 1)
		l->coef->posy += 100;
}

void	menu_hook_posz(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 90 && y <= 115) && k == 1)
		l->coef->posz -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 90 && y <= 115) && k == 1)
		l->coef->posz -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 90 && y <= 115) && k == 1)
		l->coef->posz -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 90 && y <= 115) && k == 1)
		l->coef->posz += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 90 && y <= 115) && k == 1)
		l->coef->posz += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 90 && y <= 115) && k == 1)
		l->coef->posz += 100;
}

void	menu_hook_rotx(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 150 && y <= 180) && k == 1)
		l->coef->rotx -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 150 && y <= 180) && k == 1)
		l->coef->rotx -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 150 && y <= 180) && k == 1)
		l->coef->rotx -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 150 && y <= 180) && k == 1)
		l->coef->rotx += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 150 && y <= 180) && k == 1)
		l->coef->rotx += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 150 && y <= 180) && k == 1)
		l->coef->rotx += 100;
}

void	menu_hook_roty(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 190 && y <= 220) && k == 1)
		l->coef->roty -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 190 && y <= 220) && k == 1)
		l->coef->roty -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 190 && y <= 220) && k == 1)
		l->coef->roty -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 190 && y <= 220) && k == 1)
		l->coef->roty += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 190 && y <= 220) && k == 1)
		l->coef->roty += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 190 && y <= 220) && k == 1)
		l->coef->roty += 100;
}

void	menu_hook_rotz(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 230 && y <= 260) && k == 1)
		l->coef->rotz -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 230 && y <= 260) && k == 1)
		l->coef->rotz -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 230 && y <= 260) && k == 1)
		l->coef->rotz -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 230 && y <= 260) && k == 1)
		l->coef->rotz += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 230 && y <= 260) && k == 1)
		l->coef->rotz += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 230 && y <= 260) && k == 1)
		l->coef->rotz += 100;
}

void	menu_hook_strx(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 290 && y <= 320) && k == 1)
		l->coef->strx -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 290 && y <= 320) && k == 1)
		l->coef->strx -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 290 && y <= 320) && k == 1)
		l->coef->strx -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 290 && y <= 320) && k == 1)
		l->coef->strx += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 290 && y <= 320) && k == 1)
		l->coef->strx += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 290 && y <= 320) && k == 1)
		l->coef->strx += 100;
}

void	menu_hook_stry(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 330 && y <= 360) && k == 1)
		l->coef->stry -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 330 && y <= 360) && k == 1)
		l->coef->stry -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 330 && y <= 360) && k == 1)
		l->coef->stry -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 330 && y <= 360) && k == 1)
		l->coef->stry += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 330 && y <= 360) && k == 1)
		l->coef->stry += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 330 && y <= 360) && k == 1)
		l->coef->stry += 100;
}

void	menu_hook_strz(int k, int x, int y, t_control *l)
{
	if ((x >= (W + 45) + 16 && x <= (W + 45) + 48) && (y >= 370 && y <= 400) && k == 1)
		l->coef->strz -= 100;
	if ((x >= (W + 45) + 48 && x <= (W + 45) + 80) && (y >= 370 && y <= 400) && k == 1)
		l->coef->strz -= 10;
	if ((x >= (W + 45) + 80 && x <= (W + 45) + 112) && (y >= 370 && y <= 400) && k == 1)
		l->coef->strz -= 1;
	if ((x >= (W + 45) + 144 && x <= (W + 45) + 176) && (y >= 370 && y <= 400) && k == 1)
		l->coef->strz += 1;
	if ((x >= (W + 45) + 176 && x <= (W + 45) + 208) && (y >= 370 && y <= 400) && k == 1)
		l->coef->strz += 10;
	if ((x >= (W + 45) + 208 && x <= (W + 45) + 240) && (y >= 370 && y <= 400) && k == 1)
		l->coef->strz += 100;
}


int		menu_hook_update(int k, t_control *l)
{
		l->obj[l->coef->cur] = gen_surface(l->coef->shape, gen_attr(l->coef->color.color, l->coef->rad, l->coef->axe, l->coef->type), vec3(l->coef->posx, l->coef->posy, l->coef->posz), vec3(l->coef->rotx, l->coef->roty, l->coef->rotz), vec3(l->coef->strx / 100, l->coef->stry / 100, l->coef->strz / 100));
	multithread(l);
	return (k);
}

int		menu_hook_add(int k, t_control *l)
{
		l->coef->color.c[0] = l->coef->r;
		l->coef->color.c[1] = l->coef->g;
		l->coef->color.c[2] = l->coef->b;

		if (l->obj[l->coef->cur].attr.id == 0)
			l->coef->axe = 0;
		l->obj[l->coef->cur] = gen_surface(l->coef->shape, gen_attr(l->coef->color.color, l->coef->rad, l->coef->axe, l->coef->type), vec3(l->coef->posx, l->coef->posy, l->coef->posz), vec3(l->coef->rotx, l->coef->roty, l->coef->rotz), vec3(l->coef->strx / 100, l->coef->stry / 100, l->coef->strz / 100));
		if (l->coef->cur > l->coef->total)
			l->coef->total += 1;
		l->coef->cur = l->coef->total;
		multithread(l);
		return (k);
}

int		menu_hook_cancel(int k, t_control *l)
{
		l->obj[l->coef->cur] = l->coef->swap;
		l->av = l->coef->cur;
		multithread(l);
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
	return (k);
}
