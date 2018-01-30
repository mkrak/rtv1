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
	l->p->posx = 0;
	l->p->posy = 0;
	l->p->posz = 0;
	rt(l);
}

void		rt(t_control *l)
{
	double fov = 60 * PI / 100;
	int px = 10;
	int py = 10;
	int i = 0;

	l->s->p.posx = 0;
	l->s->p.posy = 0;
	l->s->p.posz = -55;
	l->s->ray = 20;

	// while(px < H)
	// {
	// 	while(py < W)
	// 	{
			l->p->posx = py - W / 2;
			l->p->posy =  px - H / 2;
			l->p->posz = -W / (2 * tan(fov / 2));
			printf("%f et %f et %f\n", l->p->posx, l->p->posy, l->p->posz);
			l->r->o.posx = 0;
			l->r->o.posy = 0;
			l->r->o.posz = 0;
			l->r->d.posx = l->p->posx;
			l->r->d.posy = l->p->posy;
			l->r->d.posz = l->p->posz;
			printf("%f et %f et %f\n", l->p->posx, l->p->posy, l->p->posz);

			i = intersec(l);
			if (i == 1)
				put_pixel(l->coef, px, py, 0xffffff);

			
	// 		py++;
	// 	}
	// 	px++;
	// 	py = 0;
	// }
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, l->coef->img, 0, 0);
}

int		intersec(t_control *l)
{
	double a = 1;
	double b = 2 * dot(l->p, ope_sus(&l->r->o, &l->s->p));
	double c = getnorm2(ope_sus(&l->r->o, &l->s->p)) - (l->s->ray * l->s->ray);


	double delta = b * b - 4 * a * c;

	printf("A = %f et B = %f et C = %f  et Del = %f\n", a, b, c, delta);

	if (delta < 0)
		return (0);
//	double t1 = (-b - sqrt(delta)) / (2 * a);
	double t2 = (-b + sqrt(delta)) / (2 * a);
	printf("%f\n", t2);

	if (t2 > 0)
		return (1);
	return (0);
}

double		getnorm2(t_point *p)
{
	double tmp;

	tmp = p->posx * p->posx + p->posy * p->posy + p->posz * p->posz;

	return (tmp);
}

void		normalize(t_point *p)
{
	double norm;

	norm = sqrt(getnorm2(p));
	p->posx /= norm;
	p->posy /= norm;
	p->posz /= norm;
}

t_point		*ope_sus(t_point *p, t_point *b)
{
	t_point *tmp;

	tmp = (t_point*)malloc(sizeof(t_point));
	tmp->posx = p->posx - b->posx;
	tmp->posy = p->posy - b->posy;
	tmp->posz = p->posz - b->posz;

	return (tmp);
}

t_point		*ope_add(t_point *p, t_point *b)
{
	t_point *tmp;

	tmp = NULL;
	tmp->posx = p->posx + b->posx;
	tmp->posy = p->posy + b->posy;
	tmp->posz = p->posz + b->posz;

	return (tmp);
}



t_point		*ope_mulv2(double a, t_point *b)
{
	t_point *tmp;

	tmp = NULL;
	tmp->posx = a + b->posx;
	tmp->posy = a + b->posy;
	tmp->posz = a + b->posz;

	return (tmp);
}

t_point		*ope_mulv1(t_point *b, double a)
{
	t_point *tmp;

	tmp = NULL;
	tmp->posx = a + b->posx;
	tmp->posy = a + b->posy;
	tmp->posz = a + b->posz;

	return (tmp);
}

t_point		*ope_div(t_point *p, double a)
{
	t_point *tmp;

	tmp = NULL;
	tmp->posx = p->posx / a;
	tmp->posy = p->posy / a;
	tmp->posz = p->posz / a;

	return (tmp);
}

double		dot(t_point *p, t_point *b)
{
	double dot;

	dot = p->posx * b->posx + p->posy * b->posy + p->posz * b->posz;

	return (dot);
}

