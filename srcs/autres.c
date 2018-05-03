/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autres.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:55:01 by clanier           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/05/03 20:28:19 by clanier          ###   ########.fr       */
=======
/*   Updated: 2018/05/03 19:53:46 by lgautier         ###   ########.fr       */
>>>>>>> e03ddac2f6dc25897b5fc3676b58d1f89fc65327
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec3		mult_vec3(t_vec3 a, t_vec3 b)
{
	return (vec3(a.x * b.x, a.y * b.y, a.z * b.z));
}

t_vec3		albed(int color)
{
	t_vec3	albedo;

	albedo.x = (color >> 16 & 0xff) / 255.;
	albedo.y = (color >> 8 & 0xff) / 255.;
	albedo.z = (color & 0xff) / 255.;
	return (albedo);
}

void	borne(t_vec3 *color)
{
	color->x = fmin(255, fmax(0, pow(color->x, 1 / 2.2)));
	color->y = fmin(255, fmax(0, pow(color->y, 1 / 2.2)));
	color->z = fmin(255, fmax(0, pow(color->z, 1 / 2.2)));
}

void	init_mouv(t_control *l)
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

double	getnorm2(t_vec3 p)
{
	return (p.x * p.x + p.y * p.y + p.z * p.z);
}

double	dot(t_vec3 p, t_vec3 b)
{
	return (p.x * b.x + p.y * b.y + p.z * b.z);
}

t_vec3	moy_point(t_vec3 *moy, int antial)
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
