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

t_vec3		mult_vec3(t_vec3 a, t_vec3 b)
{
	return (vec3(a.x * b.x, a.y * b.y, a.z * b.z));
}

t_vec3		rotate_cam(t_vec3 d, double x, double y, double z)
{
	t_vec3 tmp;

	tmp = rot_cam_z(rot_cam_y(rot_cam_x(d, x), y), z);
	return (tmp);
}

t_vec3		rot_cam_x(t_vec3 d, double x)
{
	t_vec3 tmp;

	x *= M_PI / 180;
	tmp.x = d.x;
	tmp.y = cos(x) * d.y - sin(x) * d.z;
	tmp.z = sin(x) * d.y + cos(x) * d.z;
	return (tmp);
}

t_vec3		rot_cam_y(t_vec3 d, double y)
{
	t_vec3 tmp;

	y *= M_PI / 180;
	tmp.x = cos(y) * d.x + sin(y) * d.z;
	tmp.y = d.y;
	tmp.z = -sin(y) * d.x + cos(y) * d.z;
	return (tmp);
}

t_vec3		rot_cam_z(t_vec3 d, double z)
{
	t_vec3 tmp;

	z *= M_PI / 180;
	tmp.x = cos(z) * d.x - sin(z) * d.y;
	tmp.y = sin(z) * d.x + cos(z) * d.y;
	tmp.z = d.z;
	return (tmp);
}
