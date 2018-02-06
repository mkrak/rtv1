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
	t_obj tmp[2];
	// l->s = init_sphere(l->s);
	

	tmp[0].s = init_sphere(init_point(0, 0, -55) , 20, init_point(1, 0, 0));
	tmp[1].s = init_sphere(init_point(0, -2020, 0) , 2000, init_point(0, 1, 0));

	l->obj[0].s = tmp[0].s;
	l->obj[1].s = tmp[1].s; 

	l->l->p  = init_point(15, 70, -30);
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

			t_point *norm = (t_point*)malloc(sizeof(t_point));
	   		t_point *pos = (t_point*)malloc(sizeof(t_point));

			t_point power;
			if(intersec(l, pos, norm))
			{	
				power = ope_mulv1(l->obj->s.color, l->l->power * fmax(0, dot(normalize(ope_sus(l->l->p, *pos)), *norm)) / getnorm2(ope_sus(l->l->p, *pos)));
				put_pixel(l->coef, px, py, power);
			}
			py++;
		}
		px++;
		py = 0;
	}
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, l->coef->img, 0, 0);
}



int		intersec(t_control *l, t_point *pos, t_point *norm)
{
	int i = 0;
	double a = 1;
	double b = 2 * dot(l->r->d, ope_sus(l->r->o, l->obj[i].s.p));
	double c = getnorm2(ope_sus(l->r->o, l->obj[i].s.p)) - (l->obj[i].s.ray * l->obj[i].s.ray);
	double delta = (b * b) - (4 * a * c);


	if (delta < 0)
		return (0);
	double t1 = (-b - sqrt(delta)) / (2 * a);	
	double t2 = (-b + sqrt(delta)) / (2 * a);

	if (t2 < 0)
		return (0);
	
	double t = 0;
	if (t1 > 0)
		t= t1;
	else
		t = t2;

	*pos = ope_add(l->r->o, ope_mulv1(l->r->d, t));  
	*norm = ope_sus(*pos, l->obj[i].s.p);
//	printf("5      norm = %f  norm = %f norm = %f\n", norm->posx, norm->posy, norm->posz);
//	printf("6      norm = %f  norm = %f norm = %f\n", pos->posx, pos->posy, pos->posz);
	return (1);
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

