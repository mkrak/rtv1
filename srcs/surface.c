/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:18:11 by lgautier          #+#    #+#             */
/*   Updated: 2018/04/30 19:18:13 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		gen_sphere(t_quadric *q, t_attr attr)
{
	q->a = 1 / pow(attr.radius, 2);
	q->b = 1 / pow(attr.radius, 2);
	q->c = 1 / pow(attr.radius, 2);
	q->j = -1;
}

void		gen_cylinder(t_quadric *q, t_attr attr)
{
	(attr.axe == 'y' || attr.axe == 'z') ? (q->a = 1 / pow(attr.radius, 2)) : (q->a = 0);
	(attr.axe == 'x' || attr.axe == 'z') ? (q->b = 1 / pow(attr.radius, 2)) : (q->b = 0);
	(attr.axe == 'x' || attr.axe == 'y') ? (q->c = 1 / pow(attr.radius, 2)) : (q->c = 0);
	q->j = -1;
}

void		gen_plane(t_quadric *q, t_attr attr)
{
	(attr.axe == 'x') ? (q->a = 1) : (q->a = 0);
	(attr.axe == 'y') ? (q->b = 1) : (q->b = 0);
	(attr.axe == 'z') ? (q->c = 1) : (q->c = 0);
	q->j = -1;
}

void		gen_cone(t_quadric *q, t_attr attr)
{
	(attr.axe == 'y' || attr.axe == 'z') ? (q->a = 1 / pow(attr.radius, 2)) : (q->a = - 1 / pow(attr.radius, 2));
	(attr.axe == 'x' || attr.axe == 'z') ? (q->b = 1 / pow(attr.radius, 2)) : (q->b = - 1 / pow(attr.radius, 2));
	(attr.axe == 'x' || attr.axe == 'y') ? (q->c = 1 / pow(attr.radius, 2)) : (q->c = - 1 / pow(attr.radius, 2));
	q->j = -1;
}

t_obj	gen_surface(int id, t_attr attr, t_vec3 coord, t_vec3 rot)
{
	t_obj		obj;
	gen_obj		*generate;

	generate = init_gen();
	obj.attr = attr;	
	obj.attr.id = id;
	obj.attr.pos = coord;
	obj.attr.rot = rot;
	generate[obj.attr.id](&obj.q, obj.attr);
	gen_quadric(&obj.q);
	rot_x(&obj.q, obj.attr.rot.x);
	rot_y(&obj.q, obj.attr.rot.y);
	rot_z(&obj.q, obj.attr.rot.z);
	translation(&obj.q, obj.attr.pos);
	return (obj);
}
