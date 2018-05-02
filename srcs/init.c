/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/05/02 18:41:02 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
/*
t_obj		*init_obj(int nb_obj)
{
	int		c;
	double	h;
	t_obj	*obj;

	c = 0x333333;
	h = 0.75;
	obj = (t_obj*)malloc(sizeof(t_obj) * nb_obj);
	obj[0] = init_object(0, gen_attr(0x00ff7f, 12, 0, 0), vec3(0, 0, -30), vec3(0, 0, 0), vec3(1, 1, 1));
	obj[1] = init_object(1, gen_attr(0xffffff, 0, 'y', 0), vec3(0, -25, 0), vec3(0, 0, 0), vec3(1, 1, 1));
	obj[2] = init_object(1, gen_attr(0xffffff, 0, 'y', 0), vec3(0, 25, 0), vec3(0, 0, 0), vec3(1, 1, 1));
	obj[3] = init_object(1, gen_attr(0xffffff, 0, 'x', 0), vec3(50, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1));
	obj[4] = init_object(1, gen_attr(0xffffff, 0, 'x', 0), vec3(-50, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1));
	obj[5] = init_object(1, gen_attr(0xffffff, 0, 'z', 0), vec3(0, 0, -75), vec3(0, 0, 0), vec3(1, 1, 1));
	obj[6] = init_object(1, gen_attr(0xffffff, 0, 'z', 0), vec3(0, 0, 75), vec3(0, 0, 0), vec3(1, 1, 1));
	obj[7] = init_object(2, gen_attr(0x7fff00, 5, 'x', 2), vec3(0, 0, -30), vec3(0, 45, 0), vec3(1, 1, 1));
	obj[8] = init_object(2, gen_attr(0xff007f, 6, 'y', 2), vec3(0, 0, -30), vec3(0, 0, 0), vec3(1, 1, 1));
	obj[9] = init_object(3, gen_attr(0x7f0000, 25, 'y', 1), \
		vec3(-50, -25, -60), vec3(0, 0, 0), vec3(0.1, 1, 1));
	return (obj);
}
*/
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
	l->coef->pn = 0;
	l->coef->total = l->nb_obj;
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
