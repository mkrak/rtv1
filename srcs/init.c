/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/04/25 23:37:24 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_obj		*init_obj(int nb_obj)
{
	int		c;
	double	h;
	t_obj	*obj;

	c = 0x333333;
	h = 0.75;
	obj = (t_obj*)malloc(sizeof(t_obj) * nb_obj);
	obj[0] = gen_surface(0, gen_attr(0x00ff7f, 12, 0, 0), vec3(0, 0, -30));
	obj[1] = gen_surface(1, gen_attr(0xffffff, 0, 'y', 0), vec3(0, -25, 0));
	obj[2] = gen_surface(1, gen_attr(0xffffff, 0, 'y', 0), vec3(0, 25, 0));
	obj[3] = gen_surface(1, gen_attr(0xffffff, 0, 'x', 0), vec3(50, 0, 0));
	obj[4] = gen_surface(1, gen_attr(0xffffff, 0, 'x', 0), vec3(-50, 0, 0));
	obj[5] = gen_surface(1, gen_attr(0xffffff, 0, 'z', 0), vec3(0, 0, -75));
	obj[6] = gen_surface(1, gen_attr(0xffffff, 0, 'z', 0), vec3(0, 0, 75));
	obj[7] = gen_surface(2, gen_attr(0x7fff00, 5, 'x', 2), vec3(0, 0, -30));
	obj[8] = gen_surface(2, gen_attr(0xff007f, 6, 'y', 2), vec3(0, 0, -30));
	obj[9] = gen_surface(3, gen_attr(0x7f0000, 25, 'y', 2), \
		vec3(-50, -25, -60));
	return (obj);
}

void		init_coef(t_control *l)
{
	l->coef->rot_x = 0;
	l->coef->rot_y = 0;
	l->coef->rot_z = 0;
	l->coef->pos_x = 70;
	l->coef->pos_y = 0;
	l->coef->pos_z = 0;
	l->coef->cartoon = 0;
	l->coef->wtf = 0;
	l->coef->negatif = 0;
	l->coef->sepia = 0;
	l->coef->bnw = 0;
	l->coef->sat = 100;
	l->coef->reflec = 1;
	l->coef->sat = 100;
	l->coef->cur = 8;
	l->coef->total = 8;
}

void		init_w(t_control *l)
{
	init_coef(l);
	l->l[0].p = vec3(0, 20, 70);
	l->l[0].power = 156660000;
//	l->l[1].p = vec3(30, 0, 25);
//	l->l[1].power = 36666000;
//	l->l[2].p = vec3(-30, 0, 25);
//	l->l[2].power = 36666000;
	l->aliasing = 4;
	l->antial = 1;
	multithread(l);
}

t_vec3		vec3(double x, double y, double z)
{
	t_vec3 tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}

t_sphere	init_sphere(t_vec3 p, double ray, t_vec3 color, int type)
{
	t_sphere tmp;

	tmp.p = vec3(p.x, p.y, p.z);
	tmp.ray = ray;
	tmp.color = color;
	tmp.type = type;
	return (tmp);
}