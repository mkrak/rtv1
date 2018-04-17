/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/01/22 19:57:54 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

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

t_point		ope_divv1(t_point b, double a)
{
	return (init_point(b.posx / a, b.posy / a, b.posz / a));
}