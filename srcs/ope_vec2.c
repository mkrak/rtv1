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

t_vec3		rotate_cam(t_vec3 d, double x, double y, double z)
{
	t_vec3 tmp;

	tmp = rot_z(rot_y(rot_x(d, x), y), z);
 
	return (tmp);
}

t_vec3		rot_x(t_vec3 d, double x)
{
	t_vec3 tmp;

	x *= M_PI / 180;
	tmp.x = d.x;
	tmp.y = cos(x) * d.y - sin(x) * d.z;
	tmp.z = sin(x) * d.y + cos(x) * d.z;
	
	return (tmp);
}

t_vec3		rot_y(t_vec3 d, double y)
{
	t_vec3 tmp;

	y *= M_PI / 180;
	tmp.x = cos(y) * d.x + sin(y) * d.z;
	tmp.y = d.y;
	tmp.z = -sin(y) * d.x + cos(y) * d.z;
	
	return (tmp);
}

t_vec3		rot_z(t_vec3 d, double z)
{
	t_vec3 tmp;

	z *= M_PI / 180;
	tmp.x = cos(z) * d.x - sin(z) * d.y;
	tmp.y = sin(z) * d.x + cos(z) * d.y;
	tmp.z = d.z;
	
	return (tmp);
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
