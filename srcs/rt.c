/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/04/25 22:40:50 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		increment(t_pxl *p)
{
	p->x++;
	p->y = 0;
}

void		rt(t_thread *l)
{
	t_vec3	power;
	t_vec3	*moy;
	t_pxl	p;
	t_ray	ray;
	int		i;

	p = init_pxl(l->n * (H / 8), 0);
	moy = (t_vec3*)malloc(sizeof(t_vec3) * l->l.antial);
	while (p.x < (l->n + 1) * (H / 8) + 1)
	{
		while (p.y < W)
		{
			while (i < l->l.antial && (p.y % (int)fmax(l->l.aliasing, 1) == 0))
			{
				ray = anti_alias(p.x, p.y, ray, i, l->l.coef);
				moy[i] = aliasing(&l->l, ray);
				i++;
			}
			power = moy_point(moy, l->l.antial);
			put_pixel(l->i, init_pxl(p.x - (l->n * (H / 8)), p.y),\
			power, l->l.coef);
			p.y++;
		}
		increment(&p);
	}
}

t_pxl		init_pxl(int x, int y)
{
	t_pxl p;

	p.x = x;
	p.y = y;
	return (p);
}

t_vec3		get_color(t_control *l, int nb_ite, t_ray ray)
{
	int		i;
	t_inter	t;
	t_inter	inter;
	t_vec3	power;

	power = vec3(0, 0, 0);
	i = 0;
	t.t = 0;
	if (nb_ite == 0)
		return (vec3(0, 0, 0));
	while (i < l->nb_obj)
	{
		inter = intersec(i, l->obj[i].q, ray.origin, ray.dir, l);
		if ((inter.t != 0 && t.t == 0) || (inter.t < t.t && inter.t != 0))
			t = inter;
		i++;
	}
	if (t.t != 0)
	{
		if (OBJ.attr.type == 1)
		{
			ray.origin = add_vec3(t.pos, k_vec3(0.001, t.norm));
			ray.dir = sub_vec3(ray.dir, k_vec3(dot(t.norm, ray.dir) * 2,\
			t.norm));
			power = get_color(l, nb_ite - 1, ray);
			power = ope_divv1(power, l->coef->reflec);
			if (l->coef->reflec != 1)
			{
				power = add_vec3(power, ope_divv1(ombre(ray, l, t),\
				fmax((15 / l->coef->reflec), 1)));
			}
		}
		else if (OBJ.attr.type == 2)
		{
			power = damier(l, t);
		}
		else
			power = ombre(ray, l, t);
	}
	return (power);
}

t_inter		intersec(int i, t_quadric q, t_vec3 eye, t_vec3 dir, t_control *l)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	t_inter	ret;
	double	t1;
	double	t2;

	a = (q.a * pow(dir.x, 2)) + (q.b * pow(dir.y, 2)) + (q.c * pow(dir.z, 2))\
		+ (q.d * dir.y * dir.z) + (q.e * dir.x * dir.z) + (q.f * dir.x * dir.y);
	b = 2 * (q.a * eye.x * dir.x + q.b * eye.y * dir.y + q.c * eye.z * dir.z)\
		+ q.d * (eye.y * dir.z + eye.z * dir.y) + q.e * (eye.x * dir.z + eye.z\
		* dir.x) + q.f * (eye.x * dir.y + eye.y * dir.x) + q.g * dir.x + q.h\
		* dir.y + q.i * dir.z;
	c = q.a * pow(eye.x, 2) + q.b * pow(eye.y, 2) + q.c * pow(eye.z, 2) + q.d\
		* eye.y * eye.z + q.e * eye.x * eye.z + q.f * eye.x * eye.y + q.g\
		* eye.x + q.h * eye.y + q.i * eye.z + q.j;
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
	{
		ret.t = 0;
		return (ret);
	}
	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	ret.id = i;
	if (t2 < 0)
	{
		ret.t = 0;
		return (ret);
	}
	if (t1 > 0)
		ret.t = t1;
	else
		ret.t = t2;
	ret.pos = add_vec3(eye, k_vec3(ret.t, dir));
	ret.norm = normalize(get_normal(q, ret.pos));
	if (l->coef->pn)
	{
		ret.norm.x = ret.norm.x + (sin(ret.pos.x) * 0.5);
		ret.norm = normalize(ret.norm);
	}
	return (ret);
}

t_vec3		ombre(t_ray ray, t_control *l, t_inter t)
{
	int		i;
	t_inter	ombre;
	t_inter	inter;
	t_vec3	power;
	double	dist_l2;

	i = 0;
	ombre.t = 0;
	ray.origin = add_vec3(t.pos, k_vec3(0.001, t.norm));
	ray.dir = normalize(sub_vec3(l->l[l->obj_i].p, t.pos));
	while (i < l->nb_obj)
	{
		inter = intersec(i, l->obj[i].q, ray.origin, ray.dir, l);
		if ((ombre.t == 0 && inter.t != 0)\
		|| (inter.t < ombre.t && inter.t != 0))
			ombre = inter;
		i++;
	}
	dist_l2 = getnorm2(sub_vec3(l->l[l->obj_i].p, t.pos));
	if (ombre.t != 0 && ombre.t * ombre.t < dist_l2)
		power = vec3(0, 0, 0);
	else
		power = k_vec3(l->l[l->obj_i].power * fmax(0, dot(ray.dir, t.norm))\
		/ dist_l2, OBJ.attr.albedo);
	return (power);
}
