/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/01/22 19:57:54 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		rt(t_control *l)
{
	t_point power;
	double fov = 60 * M_PI / 180;
	int px = 0;
	int py = 0;
	t_ray ray;

	while(px < H)
	{
		while(py < W)
		{
			ray.d = normalize(init_point(py - W / 2, px - H / 2, -W / (2 * tan(fov / 2))));
			ray.d = rotate_cam(ray.d, 0);
			ray.o = init_point(0, 0, 80);
			power = init_point(0, 0, 0);
			l->obj_i = 0;
			while (l->obj_i < l->nb_luz)
			{
				power = ope_add(power, get_color(l, 5, ray));
				l->obj_i++;
			}

			put_pixel(l->coef, px, py, ope_add(power, init_point(0, 0, 0)));
			py++;
		}
		px++;
		py = 0;
	}
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, l->coef->img, 0, 0);
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

t_point			damier(t_control *l, t_inter inter)
{
    t_damier	a;
    t_point color = init_point(0, 0, 0);

    a.px = inter.pos.posx - l->obj[inter.id].s.p.posx;
    a.py = inter.pos.posy - l->obj[inter.id].s.p.posy;
    a.pz = inter.pos.posz - l->obj[inter.id].s.p.posz;
	a.x1 = (int)(floor((a.px / LENGHT_PROCED)));
	a.y1 = (int)(floor((a.py / LENGHT_PROCED)));
	a.z1 = (int)(floor((a.pz / LENGHT_PROCED)));

    if (a.x1 % 2 == 0)
    {
        if(((a.y1 % 2 == 0) && (a.z1 % 2 == 0)) || (((a.y1 % 2 != 0) && (a.z1 % 2 != 0))))
        {
            color.posx = 0;
            color.posy = 0;
            color.posz = 0;
        }
        else
        {
            color.posx = 255;
            color.posy = 255;
            color.posz = 255;
        }
    }
    else
    {
		if (((a.y1 % 2 == 0) && (a.z1 % 2 == 0)) || (((a.y1 % 2 != 0) && (a.z1 % 2 != 0))))
		{
		    color.posx = 255;
            color.posy = 255;
            color.posz = 255;
		}
		else
		{
            color.posx = 0;
            color.posy = 0;
            color.posz = 0;
		}
    }
    return (color);
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
