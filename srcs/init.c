/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/05/03 13:03:24 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		init_coef(t_control *l)
{
	l->coef->rot_x = 0;
	l->coef->rot_y = 0;
	l->coef->rot_z = 0;
	l->coef->pos_x = 0;
	l->coef->pos_y = 50;
	l->coef->pos_z = 100;
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
