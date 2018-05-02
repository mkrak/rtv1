/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:33:29 by cballest          #+#    #+#             */
/*   Updated: 2018/05/02 20:11:34 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		menu_hook_update(int k, t_control *l)
{
	t_attr	*attr;

	attr = &l->obj[l->coef->cur].attr;
	attr->id = l->coef->shape;
	attr->radius = l->coef->rad;
	attr->color = l->coef->color.color;
	attr->axe = l->coef->axe;
	attr->type = l->coef->type;
	attr->pos = vec3(l->coef->posx, l->coef->posy, l->coef->posz);
	attr->rot = vec3(l->coef->rotx, l->coef->roty, l->coef->rotz);
	attr->scale = vec3(l->coef->strx, l->coef->stry, l->coef->strz);
//	l->obj[l->coef->cur] = gen_attr(l->obj[l->coef->cur]);
	multithread(l);
	return (k);
}

int		menu_hook_add(int k, t_control *l)
{
	t_obj	*obj;

	obj = get_obj(&l->obj, l->coef->cur);
	l->coef->color.c[0] = l->coef->r;
	l->coef->color.c[1] = l->coef->g;
	l->coef->color.c[2] = l->coef->b;

	obj->attr.id = l->coef->shape;
	obj->attr.radius = l->coef->rad;
	obj->attr.color = l->coef->color.color;
	obj->attr.axe = l->coef->axe;
	obj->attr.type = l->coef->type;
	obj->attr.pos = vec3(l->coef->posx, l->coef->posy, l->coef->posz);
	obj->attr.rot = vec3(l->coef->rotx, l->coef->roty, l->coef->rotz);
	obj->attr.scale = vec3(l->coef->strx, l->coef->stry, l->coef->strz);
	gen_attr(&obj);

//	if (l->obj[l->coef->cur].attr.id == 0)
//		l->coef->axe = 0;
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

int		menu_hook_delete(int k, t_control *l)
{
	free_object_by_id(&l->obj, l->coef->cur);
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
//	else if (k == 1 && (x >= 0 && x <= 75) && (y >= 410 && y <= 750))
//		menu_hook_update(k, l);
//	else if (k == 1 && (x >= 75 && x <= 150) && (y >= 410 && y <= 750))
//		return (menu_hook_add(k, l));
//	else if (k == 1 && (x >= 150 && x <= 250) && (y >= 410 && y <= 750))
//		return (menu_hook_cancel(k, l));
	return (k);
}
