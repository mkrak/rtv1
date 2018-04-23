/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/04/03 16:08:57 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		rt(t_thread *l)
{
	t_vec3 power;
	t_vec3 *moy;
	int px = l->n * (H / 8);
	int py = 0;
	int n = 0;
	t_ray ray;
	int i = 0;

	moy = (t_vec3*)malloc(sizeof(t_vec3) * l->l.antial);

	while(px < (l->n + 1) * (H / 8) + 1)
	{
		while(py < W)
		{
			while(i < l->l.antial && (py % (int)fmax(l->l.aliasing, 1) == 0))
			{
				ray = anti_alias(px, py, ray, i, l->l.coef);
				moy[i] = aliasing(&l->l, ray);
				i++;
			}
			i = 0;
			power = moy_point(moy, l->l.antial);
			put_pixel(l->i, px - (l->n * (H / 8)), py, power, l->l.coef);
			py++;
		}
		n++;
		if ((n == 10 && l->n == 0) && (l->l.antial == 4 && l->l.aliasing < 4))
		{
			n = 0;
			ft_loadbar(l->l.coef, px * 8);
		}
		px++;
		py = 0;
	}
	//		ft_loadbar(l->l.coef, px * 8);
//	mlx_put_image_to_window(l->l.coef->mlx, l->l.coef->win, l->l.coef->img, 0, 0);
}

t_inter		inter_plane(t_control *l, int i, t_ray ray)
{
	float	n;
	float	d;
	float	res;
	t_inter	ret;

	n = OBJ_I.s.normal.x * (OBJ_I.s.p.x - ray.origin.x)
		+ OBJ_I.s.normal.y * (OBJ_I.s.p.y - ray.origin.y)
		+ OBJ_I.s.normal.z * (OBJ_I.s.p.z - ray.origin.z);
	d = OBJ_I.s.normal.x * ray.dir.x
		+ OBJ_I.s.normal.y * ray.dir.y
		+ OBJ_I.s.normal.z * ray.dir.z;
	if ((res = n / d) > 0)
	{
		ret.t = res;
		ret.pos = add_vec3(ray.origin, k_vec3(ret.t, ray.dir));  
		ret.norm = normalize(sub_vec3(ret.pos, OBJ_I.s.p));
	}
	else
		ret.t = 0;
	return (ret);
}

t_vec3		get_color(t_control *l, int nb_ite, t_ray ray)
{
	int i = 0;
	t_inter	t;
	t.t = 0;
	t_inter inter;
	t_vec3 power = vec3(0, 0, 0);

	if (nb_ite == 0)
		return (vec3(0, 0, 0));
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
			ray.origin = add_vec3(t.pos, k_vec3(0.001, t.norm));
			ray.dir = sub_vec3(ray.dir, k_vec3(dot(t.norm, ray.dir) * 2, t.norm));

			power = get_color(l, nb_ite - 1, ray);
			power = ope_divv1(power, l->coef->reflec); 
			if (l->coef->reflec != 1)
			{
				power = add_vec3(power, ope_divv1(ombre(ray, l, t), fmax((15 / l->coef->reflec), 1)));
			}
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
	double b = 2 * dot(ray.dir, sub_vec3(ray.origin, OBJ_I.s.p));
	double c = getnorm2(sub_vec3(ray.origin, OBJ_I.s.p)) - (OBJ_I.s.ray * OBJ_I.s.ray);
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
	ret.pos = add_vec3(ray.origin, k_vec3(ret.t, ray.dir));  
	ret.norm = normalize(sub_vec3(ret.pos, OBJ_I.s.p));
	return (ret);
}

t_vec3		ombre(t_ray ray, t_control *l, t_inter t)
{
	int i = 0;
	t_inter ombre;
	ombre.t = 0;
	t_inter inter;
	t_vec3 power;

	ray.origin = add_vec3(t.pos, k_vec3(0.001, t.norm));
	ray.dir = normalize(sub_vec3(l->l[l->obj_i].p, t.pos));
	
	while (i < l->nb_obj)
	{
		inter = intersec(l, i, ray);
		if ((ombre.t == 0 && inter.t != 0) || (inter.t < ombre.t && inter.t != 0))
			ombre = inter;
		i++;
	}
	double dist_l2 = getnorm2(sub_vec3(l->l[l->obj_i].p, t.pos));
 	if(ombre.t !=0 && ombre.t * ombre.t < dist_l2)
 		power = vec3(0, 0, 0);
 	else
		power = k_vec3(l->l[l->obj_i].power * fmax(0, dot(normalize(sub_vec3(l->l[l->obj_i].p, t.pos)), t.norm)) / dist_l2, OBJ.s.color);
	return (power);
}
