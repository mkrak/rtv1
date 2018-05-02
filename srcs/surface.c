/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:18:11 by lgautier          #+#    #+#             */
/*   Updated: 2018/05/02 18:32:16 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_sphere(t_quadric *q, t_attr attr)
{
	q->a = 1 / pow(attr.radius, 2);
	q->b = 1 / pow(attr.radius, 2);
	q->c = 1 / pow(attr.radius, 2);
	q->j = -1;
}

void		init_cylinder(t_quadric *q, t_attr attr)
{
	if (attr.axe == 'y' || attr.axe == 'z')
		(q->a = 1 / pow(attr.radius, 2));
	else
		(q->a = 0);
	if (attr.axe == 'x' || attr.axe == 'z')
		(q->b = 1 / pow(attr.radius, 2));
	else
		(q->b = 0);
	if (attr.axe == 'x' || attr.axe == 'y')
		(q->c = 1 / pow(attr.radius, 2));
	else
		(q->c = 0);
	q->j = -1;
}

void		init_plane(t_quadric *q, t_attr attr)
{
	if (attr.axe == 'y' || attr.axe == 'z')
		(q->a = 1);
	else
		(q->a = 0);
	if (attr.axe == 'x' || attr.axe == 'z')
		(q->b = 1);
	else
		(q->b = 0);
	if (attr.axe == 'x' || attr.axe == 'y')
		(q->c = 1);
	else
		(q->c = 0);
	q->j = -1;
}

void		init_cone(t_quadric *q, t_attr attr)
{
	if (attr.axe == 'y' || attr.axe == 'z')
		(q->a = 1 / pow(attr.radius, 2));
	else
		(q->a = -1 / pow(attr.radius, 2));
	if (attr.axe == 'x' || attr.axe == 'z')
		(q->b = 1 / pow(attr.radius, 2));
	else
		(q->b = -1 / pow(attr.radius, 2));
	if (attr.axe == 'x' || attr.axe == 'y')
		(q->c = 1 / pow(attr.radius, 2));
	else
		(q->c = -1 / pow(attr.radius, 2));
	q->j = -1;
}

void		init_object(t_obj *obj, uint32_t id)
{
	obj->attr.id = id;
	obj->attr.pos = vec3(0, 0, 0);
	obj->attr.kd = 0.8;
	obj->attr.ks = 0.8;
	obj->attr.radius = 1;
	obj->attr.type = ST_NORMAL;
	obj->attr.axe = 'y';
	obj->attr.color = 0xf70000;
	obj->attr.rot = vec3(0, 0, 0);
	obj->attr.scale = vec3(1, 1, 1);
}
