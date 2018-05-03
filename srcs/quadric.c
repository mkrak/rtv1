/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:18:04 by lgautier          #+#    #+#             */
/*   Updated: 2018/05/03 17:00:57 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_quadric(t_quadric *q)
{
	q->d = 0;
	q->e = 0;
	q->f = 0;
	q->g = 0;
	q->h = 0;
	q->i = 0;
}

void		print_q(t_quadric q)
{
		printf ("a = %f, b = %f, c = %f, d = %f, e = %f\nf = %f, g = %f, h = %f, i = %f, j = %f\n", q.a, q.b, q.c, q.d, q.e, q.f, q.g, q.h, q.i, q.j);
}

t_vec3		get_normal(t_quadric q, t_vec3 p)
{
	t_vec3	normal;

	normal.x = 2 * q.a * p.x + q.e * p.z + q.f * p.y + q.g;
	normal.y = 2 * q.b * p.y + q.d * p.z + q.f * p.x + q.h;
	normal.z = 2 * q.c * p.z + q.d * p.y + q.e * p.x + q.i;
	return (normal);
}

void	gen_attr(t_obj *obj)
{
	init_quadric(&(obj->q));
	if (g_class[obj->attr.id].init_quadric)
		g_class[obj->attr.id].init_quadric(&(obj->q), obj->attr);
	obj->attr.albedo = vec3((obj->attr.color >> 16 & 0xff) / 255., (obj->attr.color >> 8 & 0xff) / 255., (obj->attr.color & 0xff) / 255.);
	scale(&(obj->q), obj->attr.scale);
	rotate(&(obj->q), obj->attr.rot);
	translate(&(obj->q), obj->attr.pos);
}

void		translate(t_quadric *q, t_vec3 v)
{
	q->j = q->a * pow(v.x, 2) + q->b * pow(v.y, 2) + q->c * pow(v.z, 2) + q->d * v.y * v.z + q->e * v.x * v.z + q->f * v.x * v.y - q->g * v.x - q->h * v.y - q->i * v.z + q->j;
	q->g = - 2 * q->a * v.x - q->e * v.z - q->f * v.y + q->g;
	q->h = - 2 * q->b * v.y - q->d * v.z - q->f * v.x + q->h;
	q->i = - 2 * q->c * v.z - q->d * v.y - q->e * v.x + q->i;
}

void		scale(t_quadric *q, t_vec3 v)
{
	q->a = q->a / (v.x * v.x);
	q->b = q->b / (v.y * v.y);
	q->c = q->c / (v.z * v.z);
	q->d = q->d / (v.y * v.z);
	q->e = q->e / (v.x * v.z);
	q->f = q->f / (v.y * v.x);
	q->g = q->g / v.x;
	q->h = q->h / v.y;
	q->i = q->i / v.z;
}

void		rotate(t_quadric *q, t_vec3 rot)
{
		rot_x(q, rot.x);
		rot_y(q, rot.y);
		rot_z(q, rot.z);
}
