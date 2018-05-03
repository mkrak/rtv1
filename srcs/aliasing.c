/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aliasing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/05/03 12:19:52 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray				anti_alias(int px, int py, t_ray ray, int i, t_coef *t)
{
	double x;
	double y;
	double fov;

	fov = 60 * M_PI / 180;
	init_x_y(&x, &y, i);
	ray.dir = normalize(vec3((py - W / 2 + x), (px - H / 2 + y), -W / \
		(2 * tan(fov / 2))));
	ray.dir = rotate_cam(ray.dir, t->rot_x, t->rot_y, t->rot_z);
	ray.origin = vec3(t->pos_x, t->pos_y, t->pos_z);
	return (ray);
}

void				init_x_y(double *x, double *y, int i)
{
	if (i == 0)
	{
		*x = 0.25;
		*y = 0.25;
	}
	else if (i == 1)
	{
		*x = 0.75;
		*y = 0.75;
	}
	else if (i == 2)
	{
		*x = 0.25;
		*y = 0.75;
	}
	else
	{
		*x = 0.75;
		*y = 0.25;
	}
}

t_vec3				aliasing(t_control *l, t_ray ray)
{
	t_obj		*light;
	t_vec3	power;

	power = vec3(0, 0, 0);
	l->obj_i = 0;
	while (l->obj_i < l->nb_luz)
	{
		if (!(light = get_light_by_id(l->obj, l->obj_i)) && ++l->obj_i)
			continue ;
		power = add_vec3(power, get_color(l, 5, ray, light));
		l->obj_i++;
	}
	return (power);
}
