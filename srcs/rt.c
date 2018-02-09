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

void				init_w(t_control *l)
{	
	t_obj tmp[6];

	tmp[0].s = init_sphere(init_point(0, 0, -55) , 10, init_point(1, 0, 0));
//	tmp[1].s = init_sphere(init_point(4, 5, -20) , 2, init_point(0, 1, 0));
//	tmp[2].s = init_sphere(init_point(0, 0, -175) , 120, init_point(0, 0, 1));
	tmp[1].s = init_sphere(init_point(0, -2020, 0) , 2000, init_point(0.9, 1, 1));
	tmp[2].s = init_sphere(init_point(0, 2100, 0) , 2000, init_point(1, 1, 0.9));
	tmp[3].s = init_sphere(init_point(-2050, 0, 0) , 2000, init_point(0, 1, 0));
	tmp[4].s = init_sphere(init_point(2050, 0, 0) , 2000, init_point(0, 1, 1));
	tmp[5].s = init_sphere(init_point(0, 0, -2300) , 2000, init_point(1, 1, 0));

	l->obj[0].s = tmp[0].s;
	l->obj[1].s = tmp[1].s;
	l->obj[2].s = tmp[2].s;
	l->obj[3].s = tmp[3].s;
	l->obj[4].s = tmp[4].s;
	l->obj[5].s = tmp[5].s;

	l->l->p  = init_point(15, 15, -0);
	l->l->power = 80000;
	rt(l);
}


t_point		init_point(double x, double y, double z)
{
	t_point tmp;

	tmp.posx = x;
	tmp.posy = y;
	tmp.posz = z;

	return (tmp);
}


t_sphere		init_sphere(t_point p, double ray, t_point color)
{
	t_sphere tmp;

	tmp.p.posx = p.posx;
	tmp.p.posy = p.posy;
	tmp.p.posz = p.posz;
	tmp.ray = ray;
	tmp.color = color;

	return (tmp);
}

void		rt(t_control *l)
{
	t_point power;
	t_inter inter;
	t_inter t;
	double fov = 60 * PI / 180;
	int px = 0;
	int py = 0;

	while(px < H)
	{
		while(py < W)
		{
			l->r->d.posx = py - W / 2;
			l->r->d.posy = px - H / 2;
			l->r->d.posz = -W / (2 * tan(fov / 2));
			l->r->d = normalize(l->r->d);

			l->r->o.posx = 0;
			l->r->o.posy = 0;
			l->r->o.posz = 0;

			int i = 0;
			t.t = 0;
			while (i < 6)
			{
				inter = intersec(l, i);

				if (t.t == 0 && inter.t != 0)
					t = inter;
				else if (inter.t < t.t && inter.t != 0)
					t = inter;
				i++;
			}
			if(t.t !=0)
			{	
				power = ope_mulv1(l->obj[t.id].s.color, l->l->power * fmax(0, dot(normalize(ope_sus(l->l->p, t.pos)), t.norm)) / getnorm2(ope_sus(l->l->p, t.pos)));
				put_pixel(l->coef, px, py, power);
			}
			
			py++;
		}
		px++;
		py = 0;
	}
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, l->coef->img, 0, 0);
}



t_inter		intersec(t_control *l, int i)
{
	double a = 1;
	double b = 2 * dot(l->r->d, ope_sus(l->r->o, l->obj[i].s.p));
	double c = getnorm2(ope_sus(l->r->o, l->obj[i].s.p)) - (l->obj[i].s.ray * l->obj[i].s.ray);
	double delta = (b * b) - (4 * a * c);
	t_inter ret;

	if (delta < 0)
	{
		ret.t = 0;
		return (ret);
	}
	double t1 = (-b - sqrt(delta)) / (2 * a);	
	double t2 = (-b + sqrt(delta)) / (2 * a);

	if (t2 < 0)
	{
		ret.t = 0;
		return (ret);
	}
	ret.id = i;
	if (t1 > 0)
		ret.t = t1;
	else
		ret.t = t2;

	ret.pos = ope_add(l->r->o, ope_mulv1(l->r->d, ret.t));  
	ret.norm = ope_sus(ret.pos, l->obj[i].s.p);
 
	return (ret);
}

double		getnorm2(t_point p)
{
	double tmp;

	tmp = p.posx * p.posx + p.posy * p.posy + p.posz * p.posz;

	return (tmp);
}


t_point		normalize(t_point p)
{
	double norm;

	norm = sqrt(getnorm2(p));
	p.posx /= norm;
	p.posy /= norm;
	p.posz /= norm;

	return (p);
}

t_point		ope_sus(t_point p, t_point b)
{
	t_point tmp;

	tmp.posx = p.posx - b.posx;
	tmp.posy = p.posy - b.posy;
	tmp.posz = p.posz - b.posz;

	return (tmp);
}

t_point		ope_add(t_point p, t_point b)
{
	t_point tmp;

	tmp.posx = p.posx + b.posx;
	tmp.posy = p.posy + b.posy;
	tmp.posz = p.posz + b.posz;

	return (tmp);
}



t_point		ope_mulv2(t_point a, t_point b)
{
	t_point tmp;

	tmp.posx = a.posx * b.posx;
	tmp.posy = a.posx * b.posy;
	tmp.posz = a.posx * b.posz;

	return (tmp);
}

t_point		ope_mulv1(t_point b, double a)
{
	t_point tmp;

	tmp.posx = a * b.posx;
	tmp.posy = a * b.posy;
	tmp.posz = a * b.posz;

	return (tmp);
}

t_point		ope_div(t_point p, double a)
{
	t_point tmp;

	tmp.posx = p.posx / a;
	tmp.posy = p.posy / a;
	tmp.posz = p.posz / a;

	return (tmp);
}

double		dot(t_point p, t_point b)
{
	double dot;

	dot = p.posx * b.posx + p.posy * b.posy + p.posz * b.posz;

	return (dot);
}

