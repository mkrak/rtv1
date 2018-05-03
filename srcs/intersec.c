/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 21:19:33 by clanier           #+#    #+#             */
/*   Updated: 2018/05/03 21:20:24 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3		set_abc(t_quadric q, t_vec3 eye, t_vec3 dir)
{
	t_vec3	abc;

	abc.x = (q.a * pow(dir.x, 2)) + (q.b * pow(dir.y, 2)) + (q.c
	* pow(dir.z, 2)) + (q.d * dir.y * dir.z) + (q.e * dir.x * dir.z)
	+ (q.f * dir.x * dir.y);
	abc.y = 2 * (q.a * eye.x * dir.x + q.b * eye.y * dir.y + q.c * eye.z
	* dir.z) + q.d * (eye.y * dir.z + eye.z * dir.y) + q.e * (eye.x * dir.z
	+ eye.z * dir.x) + q.f * (eye.x * dir.y + eye.y * dir.x) + q.g * dir.x
	+ q.h * dir.y + q.i * dir.z;
	abc.z = q.a * pow(eye.x, 2) + q.b * pow(eye.y, 2) + q.c * pow(eye.z, 2)
	+ q.d * eye.y * eye.z + q.e * eye.x * eye.z + q.f * eye.x * eye.y + q.g
	* eye.x + q.h * eye.y + q.i * eye.z + q.j;
	return (abc);
}

t_inter		intersec(t_quadric q, t_vec3 eye, t_vec3 dir, t_control *l)
{
	t_vec3	abc;
	double	delta;
	t_inter	ret;
	double	t1;
	double	t2;

	abc = set_abc(q, eye, dir);
	delta = (abc.y * abc.y) - (4 * abc.x * abc.z);
	if (delta < 0 && !(ret.t = 0))
		return (ret);
	t1 = (-abc.y - sqrt(delta)) / (2 * abc.x);
	t2 = (-abc.y + sqrt(delta)) / (2 * abc.x);
	if (t2 < 0 && !(ret.t = 0))
		return (ret);
	ret.t = t1 > 0 ? t1 : t2;
	ret.pos = add_vec3(eye, k_vec3(ret.t, dir));
	ret.norm = normalize(get_normal(q, ret.pos));
	if (l->coef->pn)
	{
		ret.norm.x = ret.norm.x + (sin(ret.pos.x) * 0.5);
		ret.norm = normalize(ret.norm);
	}
	return (ret);
}

t_vec3		drop_shadow(t_control *l, t_inter ombre, t_inter t, t_ray ray)
{
	double	dist_l2;
	t_vec3	power;

	dist_l2 = getnorm2(sub_vec3(l->light->attr.pos, t.pos));
	if (ombre.t != 0 && ombre.t * ombre.t < dist_l2)
		power = vec3(0, 0, 0);
	else
		power = k_vec3(l->light->attr.radius * fmax(0, dot(ray.dir, t.norm))
		/ dist_l2, get_obj(&l->obj, t.id)->attr.albedo);
	return (power);
}

t_vec3		ombre(t_ray ray, t_control *l, t_inter t)
{
	int		i;
	t_inter	ombre;
	t_inter	inter;

	i = 0;
	ombre.t = 0;
	ray.origin = add_vec3(t.pos, k_vec3(0.001, t.norm));
	ray.dir = normalize(sub_vec3(l->light->attr.pos, t.pos));
	l->current = l->obj;
	while (l->current)
	{
		if (l->current->attr.id == OBJ_LIGHT && ++i)
		{
			l->current = l->current->next;
			continue ;
		}
		inter = intersec(l->current->q, ray.origin, ray.dir, l);
		inter.id = i;
		if ((!ombre.t && inter.t) || (inter.t < ombre.t && inter.t))
			ombre = inter;
		l->current = l->current->next;
		i++;
	}
	return (drop_shadow(l, ombre, t, ray));
}
