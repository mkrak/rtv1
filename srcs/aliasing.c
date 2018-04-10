/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aliasing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/04/03 15:54:10 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray				anti_alias(int px, int py, t_ray ray, int i, t_coef *t)
{
	double x = 0;
	double y = 0;
	double fov = 60 * M_PI / 180;

	if (i == 0)
	{
		x = 0.25;
		y = 0.25;
	}
	if (i == 1)
	{
		x = 0.75;
		y = 0.75;
	}
	if (i == 2)
	{
		x = 0.25;
		y = 0.75;
	}
	if (i == 3)
	{
		x = 0.75;
		y = 0.25;
	}
	ray.d = normalize(init_point((py - W / 2 + x) + t->rot_x, (px - H / 2 + y) + t->rot_y, -W / (2 * tan(fov / 2))));
	ray.d = rotate_cam(ray.d, t->rot_z);
	ray.o = init_point(t->pos_y, t->pos_z, t->pos_x);

	return (ray);
}

t_point				aliasing(int py, t_control *l, t_ray ray)
{
	t_point power;

	power = init_point(0, 0, 0);
	l->obj_i = 0;
	while (l->obj_i < l->nb_luz)
	{
		power = ope_add(power, get_color(l, 5, ray));
		l->obj_i++;
	}
	return (power);
}
