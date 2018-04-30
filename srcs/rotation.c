/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:17:46 by lgautier          #+#    #+#             */
/*   Updated: 2018/04/30 19:20:19 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		rot_z(t_quadric *q, double n)
{
	t_quadric	tmp;

	tmp = *q;
	n = n * M_PI / 180;
	q->d = tmp.d * cos(n) - tmp.e * sin(n);
	q->e = tmp.d * sin(n) + tmp.e * cos(n);
	q->g = tmp.g * cos(n) + tmp.h * sin(n);
	q->h = - tmp.g * sin(n) + tmp.h * cos(n);
	q->f = 2 * (tmp.b - tmp.a) * sin(n) * cos(n) + tmp.f * (pow(cos(n), 2) - pow(sin(n), 2));
	q->a = tmp.a * pow(cos(n), 2) + tmp.b * pow(sin(n), 2) + tmp.f * sin(n) * cos(n);
	q->b = tmp.a * pow(sin(n), 2) + tmp.b * pow(cos(n), 2) - tmp.f * sin(n) * cos(n);
}

void		rot_x(t_quadric *q, double n)
{
	t_quadric	tmp;

	tmp = *q;
	n = n * M_PI / 180;
	q->e = tmp.e * cos(n) - tmp.f * sin(n);
	q->f = tmp.e * sin(n) + tmp.f * cos(n);
	q->h = tmp.h * cos(n) + tmp.i * sin(n);
	q->i = - tmp.h * sin(n) + tmp.i * cos(n);
	q->d = (- 2 * tmp.b + 2 * tmp.c) * sin(n) * cos(n) + tmp.d * (pow(cos(n), 2) - pow(sin(n), 2));
	q->b = tmp.b * pow(cos(n), 2) + tmp.c * pow(sin(n), 2) + tmp.d * sin(n) * cos(n);
	q->c = tmp.b * pow(sin(n), 2) + tmp.c * pow(cos(n), 2) - tmp.d * sin(n) * cos(n);
}

void		rot_y(t_quadric *q, double n)
{
	t_quadric	tmp;

	tmp = *q;
	n = n * M_PI / 180;
	q->d = tmp.d * cos(n) - tmp.f * sin(n);
	q->f = tmp.d * sin(n) + tmp.f * cos(n);
	q->g = tmp.g * cos(n) + tmp.i * sin(n);
	q->i = - tmp.g * sin(n) + tmp.i * cos(n);
	q->e = 2 * (tmp.c - tmp.a) * sin(n) * cos(n) + tmp.e * (pow(cos(n), 2) - pow(sin(n), 2));
	q->a = tmp.a * pow(cos(n), 2) + tmp.c * pow(sin(n), 2) + tmp.e * sin(n) * cos(n);
	q->c = tmp.a * pow(sin(n), 2) + tmp.c * pow(cos(n), 2) - tmp.e * sin(n) * cos(n);
}
