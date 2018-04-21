/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/04/03 16:11:52 by cballest         ###   ########.fr       */
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
	l->obj[5].s = init_sphere(init_point(0, 0, -5140) , 5000, init_point(1, 1, 0), 1); //fond
	l->obj[6].s = init_sphere(init_point(0, 0, 5100) , 5000, init_point(1, 0, 1), 0);  //derriere
	l->obj[7].s = init_sphere(init_point(-15, 10, -55) , 12, init_point(0, 1, 0), 2);

	l->l[0].p  = init_point(-25, 40, -25);
	l->l[0].power = 156660000;
	//l->l[1].p  = init_point(25, 40, -25);
	//l->l[1].power = 36666000;
	//l->l[2].p  = init_point(0, -19, 0);
	//l->l[2].power = 36666000;

	l->coef->rot_x = 0;
	l->coef->rot_y = 0;
	l->coef->rot_z = 0;
	l->coef->pos_x = 0;
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
	l->aliasing = 4; //pas de max, min 1, si inferieur utilise 1
	l->antial = 1; // 1 pour non 4 pour oui bug sinon

	multithread(l);
}


t_vec3		init_point(double x, double y, double z)
{
	t_vec3 tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;

	return (tmp);
}

t_sphere		init_sphere(t_vec3 p, double ray, t_vec3 color, int type)
{
	t_sphere tmp;

	tmp.p = init_point(p.x, p.y, p.z);
	tmp.ray = ray;
	tmp.color = color;
	tmp.type = type;
	
	return (tmp);
}
