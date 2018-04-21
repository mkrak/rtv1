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

double		getnorm2(t_vec3 p)
{
	return (p.x * p.x + p.y * p.y + p.z * p.z);
}

t_vec3		normalize(t_vec3 v)
{
	double norm;

	norm = sqrt(getnorm2(v));
	return (init_point(v.x / norm, v.y / norm, v.z / norm));
}

t_vec3		sub_vec3(t_vec3 a, t_vec3 b)
{
	return (init_point(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vec3		add_vec3(t_vec3 a, t_vec3 b)
{
	return (init_point(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec3		k_vec3(double k, t_vec3 b)
{
	return (init_point(k * b.x, k * b.y, k * b.z));
}

t_vec3		ope_divv1(t_vec3 b, double a)
{
	return (init_point(b.x / a, b.y / a, b.z / a));
}