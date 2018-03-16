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
	l->obj[0].s = init_sphere(init_point(15, 10, -55) , 12, init_point(1, 0, 0), 0);
	l->obj[1].s = init_sphere(init_point(0, -5020, 0) , 5000, init_point(1, 1, 1), 0); // bas
	l->obj[2].s = init_sphere(init_point(0, 5050, 0) , 5000, init_point(0.5, 0.5, 0), 0); //haut
	l->obj[3].s = init_sphere(init_point(-5050, 0, 0) , 5000, init_point(0, 1, 0), 0); // gauche
	l->obj[4].s = init_sphere(init_point(5050, 0, 0) , 5000, init_point(0, 1, 1), 0);  // droite
	l->obj[5].s = init_sphere(init_point(0, 0, -5140) , 5000, init_point(1, 1, 0), 0); //fond
	l->obj[6].s = init_sphere(init_point(0, 0, 5100) , 5000, init_point(1, 0, 1), 0);  //derriere
	l->obj[7].s = init_sphere(init_point(-15, 10, -55) , 12, init_point(0, 1, 0), 0);

	l->l[0].p  = init_point(-25, 40, -25);
	l->l[0].power = 96660000;
	l->l[1].p  = init_point(25, 40, -25);
	l->l[1].power = 96666000;
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

t_sphere		init_sphere(t_point p, double ray, t_point color, int type)
{
	t_sphere tmp;

	tmp.p = init_point(p.posx, p.posy, p.posz);
	tmp.ray = ray;
	tmp.color = color;
	tmp.type = type;
	
	return (tmp);
}

void		rt(t_control *l)
{
	t_point power;
	double fov = 60 * M_PI / 180;
	int px = 0;
	int py = 0;

	while(px < H)
	{
		while(py < W)
		{
			power = init_point(0, 0, 0);
			RAY->d = normalize(init_point(py - W / 2, px - H / 2, -W / (2 * tan(fov / 2))));
			RAY->d = rotate_cam(RAY->d);
			RAY->o = init_point(0, 0, 80);
			
			int i = 0;

			while (i < 2)
			{
				power = ope_add(power, get_color(l, 5, i));
				i++;
			}

			put_pixel(l->coef, px, py, power);
			py++;
		}
		px++;
		py = 0;
	}
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, l->coef->img, 0, 0);
}

t_point		rotate_cam(t_point d)
{
	t_point tmp;
	double n;

	n =  0 * M_PI / 180;
	// tmp.posx = d.posx;
	// tmp.posy = cos(n) * d.posy - sin(n) * d.posz;
	// tmp.posz = sin(n) * d.posy + cos(n) * d.posz;


	// tmp.posx = cos(n) * d.posx + sin(n) * d.posz;
	// tmp.posy = d.posy;
	// tmp.posz = -sin(n) * d.posx + cos(n) * d.posz;

	tmp.posx = cos(n) * d.posx - sin(n) * d.posy;
	tmp.posy = sin(n) * d.posx + cos(n) * d.posy;
	tmp.posz = d.posz;

	return (tmp);
}

t_point		get_color(t_control *l, int nb_ite, int j)
{
	int i = 0;
	t_inter	t;
	t.t = 0;
	t_inter inter;
	t_point power = init_point(0, 0, 0);

	if (nb_ite == 0)
		return (init_point(0, 0, 0));

	while (i < l->av)
	{
		inter = intersec(l, i);
		if ((inter.t != 0 && t.t == 0) || (inter.t < t.t && inter.t != 0))
			t = inter;
		i++;
	}
	if(t.t !=0)
	{	
		// if (l->obj[t.id].s.type == 1)
		// {	
		// 	RAY->o = ope_add(t.pos, ope_mulv1(t.norm, 0.001));
		// 	//RAY->d = normalize(ope_sus(RAY->d, ope_mulv1(t.norm, dot(t.norm, RAY->d) * 2)));
		// 	RAY->d = ope_sus(RAY->d, ope_mulv1(t.norm, dot(t.norm, RAY->d) * 2));
		// 	//printf("x = %f y = %f z = %f\n", RAY->d.posx, RAY->d.posy, RAY->d.posz);
		// 	power = get_color(l, nb_ite - 1, j);
		// }
		// else
		// {
			RAY->o = ope_add(t.pos, ope_mulv1(t.norm, 0.001));
			RAY->d = normalize(ope_sus(l->l[j].p, t.pos));
			i = 0;
			t_inter ombre;
			ombre.t = 0;
			while (i < l->av)
			{
				inter = intersec(l, i);
				if ((ombre.t == 0 && inter.t != 0) || (inter.t < ombre.t && inter.t != 0))
					ombre = inter;
				i++;
			}
		 	double dist_l2 = getnorm2(ope_sus(l->l[j].p, t.pos));
		 	if(ombre.t !=0 && ombre.t * ombre.t < dist_l2)
		 		power = init_point(0, 0, 0);
		 	else
			power = ope_mulv1(l->obj[t.id].s.color, l->l[j].power * fmax(0, dot(normalize(ope_sus(l->l[j].p, t.pos)), t.norm)) / dist_l2);
		//}
	}
	return (power);
}

t_inter		intersec(t_control *l, int i)
{
	double a = 1;
	double b = 2 * dot(RAY->d, ope_sus(RAY->o, l->obj[i].s.p));
	double c = getnorm2(ope_sus(RAY->o, l->obj[i].s.p)) - (l->obj[i].s.ray * l->obj[i].s.ray);
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
	ret.pos = ope_add(RAY->o, ope_mulv1(RAY->d, ret.t));  
	ret.norm = normalize(ope_sus(ret.pos, l->obj[i].s.p));
	return (ret);
}

double		getnorm2(t_point p)
{
	return (p.posx * p.posx + p.posy * p.posy + p.posz * p.posz);
}

t_point		normalize(t_point p)
{
	double norm;

	norm = sqrt(getnorm2(p));
	return (init_point(p.posx / norm, p.posy / norm, p.posz / norm));
}

t_point		ope_sus(t_point p, t_point b)
{
	return (init_point(p.posx - b.posx, p.posy - b.posy, p.posz - b.posz));
}

t_point		ope_add(t_point p, t_point b)
{
	return (init_point(p.posx + b.posx, p.posy + b.posy, p.posz + b.posz));
}

t_point		ope_mulv1(t_point b, double a)
{
	return (init_point(a * b.posx, a * b.posy, a * b.posz));
}

t_point		ope_div(t_point p, double a)
{
	return (init_point(p.posx / a, p.posy / a, p.posz / a));
}

t_point		ope_div2v(t_point p, t_point b)
{
	return (init_point(p.posx * b.posx, p.posy * b.posy, p.posz * b.posz));
}

t_point		ope_mult2v(t_point p, t_point b)
{
	return (init_point(p.posx * b.posx, p.posy * b.posy, p.posz * b.posz));
}

double		dot(t_point p, t_point b)
{
	return (p.posx * b.posx + p.posy * b.posy + p.posz * b.posz);
}

