/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autres_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:27:43 by clanier           #+#    #+#             */
/*   Updated: 2018/05/03 20:28:37 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3	albed(int color)
{
	t_vec3	albedo;

	albedo.x = (color >> 16 & 0xff) / 255.;
	albedo.y = (color >> 8 & 0xff) / 255.;
	albedo.z = (color & 0xff) / 255.;
	return (albedo);
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

int		check_arg(int ac, char **av)
{
	if (ac != 2 && av)
	{
		ft_putendl("Usage : ../rt [Scene valide]");
		return (-1);
	}
	else
		return (1);
}

void	filtre(t_coef *c, t_vec3 *color)
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

void	increment(t_pxl *p)
{
	p->x++;
	p->y = 0;
}
