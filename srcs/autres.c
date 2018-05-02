/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*     rt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:02:30 by mkrakows          #+#    #+#             */
/*   Updated: 2018/04/27 17:12:48 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void				borne(t_vec3 *color)
{
	color->x = fmin(255, fmax(0, pow(color->x, 1 / 2.2)));
	color->y = fmin(255, fmax(0, pow(color->y, 1 / 2.2)));
	color->z = fmin(255, fmax(0, pow(color->z, 1 / 2.2)));
}

void		init_mouv(t_control *l)
{
	l->roll = 0;
	l->rolr = 0;
	l->rotl = 0;
	l->rotr = 0;
	l->rotu = 0;
	l->rotd = 0;
	l->au = 0;
	l->ad = 0;
	l->al = 0;
	l->ar = 0;
	l->ctrl = 0;
	l->shif = 0;
	l->kalisub = 0;
	l->kaliadd = 0;
	l->kaa = 0;
}

double		getnorm2(t_vec3 p)
{
	return (p.x * p.x + p.y * p.y + p.z * p.z);
}

double		dot(t_vec3 p, t_vec3 b)
{
	return (p.x * b.x + p.y * b.y + p.z * b.z);
}

t_vec3		moy_point(t_vec3 *moy, int antial)
{
	t_vec3 ret;

	if (antial == 4)
	{
		ret.x = (moy[0].x + moy[1].x + moy[2].x + moy[3].x) / antial;
		ret.y = (moy[0].y + moy[1].y + moy[2].y + moy[3].y) / antial;
		ret.z = (moy[0].z + moy[1].z + moy[2].z + moy[3].z) / antial;
	}
	else
	{
		ret.x = (moy[0].x) / antial;
		ret.y = (moy[0].y) / antial;
		ret.z = (moy[0].z) / antial;
	}
	return (ret);
}

void	gen_quadric(t_quadric *q)
{
	q->d = 0.0;
	q->e = 0.0;
	q->f = 0.0;
	q->g = 0.0;
	q->h = 0.0;
	q->i = 0.0;
}

int				check_arg(int ac, char **av)
{
	if (ac != 2 && av)
	{
		ft_putendl("Usage : ../rt [Scene valide]");
		return (-1);
	}
	else
		return (1);
}

void				filtre(t_coef *c, t_vec3 *color)
{
	if (!c->wtf)
		borne(color);
	if (c->cartoon == 1)
		cartoon(color);
	if (c->negatif == 1)
		negatif(color);
	if (c->bnw)
		black_n_white(color);
	if (c->sepia)
		sepia(color);
}

void		increment(t_pxl *p)
{
	p->x++;
	p->y = 0;
}
