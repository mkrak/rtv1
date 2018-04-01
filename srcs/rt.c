/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/03/30 17:45:38 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		rt(t_thread *l)
{
	t_point power;
	t_point *moy;
	int px = l->n * (H / 8);
	int py = 0;
	int n = 0;
	t_ray ray;
	int i = 0;

	moy = (t_point*)malloc(sizeof(t_point) * l->l.antial);

	while(px < (l->n + 1) * (H / 8))
	{
		while(py < W)
		{
			while(i < l->l.antial)
			{	
				ray = anti_alias(px, py, ray, i, l->l.coef);
				moy[i] = aliasing(py, &l->l, ray);
				i++;
			}
			i = 0;
			power = moy_point(moy, l->l.antial);
			put_pixel(l->i, px - (l->n * (H / 8)), py, power);
			py++;
		}
		n++;
		if (n == 10 && l->n == 0)
		{
			n = 0;
			ft_loadbar(l->l.coef, px * 8);
		}
		px++;
		py = 0;
	}
//	mlx_put_image_to_window(l->l.coef->mlx, l->l.coef->win, l->l.coef->img, 0, 0);
}

t_point		get_color(t_control *l, int nb_ite, t_ray ray)
{
	int i = 0;
	t_inter	t;
	t.t = 0;
	t_inter inter;
	t_point power = init_point(0, 0, 0);

	if (nb_ite == 0)
		return (init_point(0, 0, 0));
	while (i < l->nb_obj)
	{
		inter = intersec(l, i, ray);
		if ((inter.t != 0 && t.t == 0) || (inter.t < t.t && inter.t != 0))
			t = inter;
		i++;
	}
	if(t.t !=0)
	{	
		if (OBJ.s.type == 1)
		{	
			ray.o = ope_add(t.pos, ope_mulv1(t.norm, 0.001));
			ray.d = ope_sus(ray.d, ope_mulv1(t.norm, dot(t.norm, ray.d) * 2));
			power = get_color(l, nb_ite - 1, ray);
		}
		else if (OBJ.s.type == 2)
		{
			power = damier(l, t);
		}
		else
			power = ombre(ray, l, t);			
	}
	return (power);
}

t_inter		intersec(t_control *l, int i, t_ray ray)
{
	double a = 1;
	double b = 2 * dot(ray.d, ope_sus(ray.o, OBJ_I.s.p));
	double c = getnorm2(ope_sus(ray.o, OBJ_I.s.p)) - (OBJ_I.s.ray * OBJ_I.s.ray);
	double delta = (b * b) - (4 * a * c);
	t_inter ret;

	if (delta < 0)
	{
		ret.t = 0;
		return (ret);
	}
	double t1 = (-b - sqrt(delta)) / (2 * a);	
	double t2 = (-b + sqrt(delta)) / (2 * a);
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
	ret.pos = ope_add(ray.o, ope_mulv1(ray.d, ret.t));  
	ret.norm = normalize(ope_sus(ret.pos, OBJ_I.s.p));
	return (ret);
}

t_point		ombre(t_ray ray, t_control *l, t_inter t)
{
	int i = 0;
	t_inter ombre;
	ombre.t = 0;
	t_inter inter;
	t_point power;

	ray.o = ope_add(t.pos, ope_mulv1(t.norm, 0.001));
	ray.d = normalize(ope_sus(l->l[l->obj_i].p, t.pos));
	
	while (i < l->nb_obj)
	{
		inter = intersec(l, i, ray);
		if ((ombre.t == 0 && inter.t != 0) || (inter.t < ombre.t && inter.t != 0))
			ombre = inter;
		i++;
	}
	double dist_l2 = getnorm2(ope_sus(l->l[l->obj_i].p, t.pos));
 	if(ombre.t !=0 && ombre.t * ombre.t < dist_l2)
 		power = init_point(0, 0, 0);
 	else
		power = ope_mulv1(OBJ.s.color, l->l[l->obj_i].power * fmax(0, dot(normalize(ope_sus(l->l[l->obj_i].p, t.pos)), t.norm)) / dist_l2);
	return (power);
}
