/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/05/03 21:20:38 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

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
			i = 0;
			while (i < l->l.antial && (p.y % (int)fmax(l->l.aliasing, 1) == 0))
			{
				ray = anti_alias(p, ray, i, l->l.coef);
				moy[i] = aliasing(&l->l, ray);
				i++;
			}
			power = moy_point(moy, l->l.antial);
			put_pixel(l->i, init_pxl(p.x - (l->n * (H / 8)), ++p.y),\
			power, l->l.coef);
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

t_vec3		get_color_inter(t_control *l, int nb_ite, t_inter t, t_ray ray)
{
	t_vec3	power;

	power = vec3(0, 0, 0);
	if (t.t != 0)
	{
		if (get_obj(&l->obj, t.id)->attr.type == 1)
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
		else if (get_obj(&l->obj, t.id)->attr.type == ST_CHECKER_BOARD)
			power = damier(l, t);
		else
			power = ombre(ray, l, t);
	}
	return (power);
}

t_vec3		get_color(t_control *l, int nb_ite, t_ray ray)
{
	int		i;
	t_inter	t;
	t_inter	inter;

	i = 0;
	t.t = 0;
	if (nb_ite == 0)
		return (vec3(0, 0, 0));
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
		if ((inter.t != 0 && t.t == 0) || (inter.t < t.t && inter.t != 0))
			t = inter;
		l->current = l->current->next;
		i++;
	}
	return (get_color_inter(l, nb_ite, t, ray));
}
