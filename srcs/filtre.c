/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/04/25 22:40:50 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void				cartoon(t_vec3 *color)
{
	if (color->z > 0 && color->z < 50)
		color->z = 25;
	else if (color->z >= 50 && color->z < 100)
		color->z = 75;
	else if (color->z >= 100 && color->z < 150)
		color->z = 125;
	else if (color->z >= 150 && color->z < 200)
		color->z = 175;
	else if (color->z >= 200 && color->z <= 255)
		color->z = 225;
	if (color->y > 0 && color->y < 50)
		color->y = 25;
	else if (color->y >= 50 && color->y < 100)
		color->y = 75;
	else if (color->y >= 100 && color->y < 150)
		color->y = 125;
	else if (color->y >= 150 && color->y < 200)
		color->y = 175;
	else if (color->y >= 200 && color->y <= 255)
		color->y = 225;
	carton(color);
}

void				carton(t_vec3 *color)
{
	if (color->x > 0 && color->x < 50)
		color->x = 25;
	else if (color->x >= 50 && color->x < 100)
		color->x = 75;
	else if (color->x >= 100 && color->x < 150)
		color->x = 125;
	else if (color->x >= 150 && color->x < 200)
		color->x = 175;
	else if (color->x >= 200 && color->x <= 255)
		color->x = 225;
}

void				sepia(t_vec3 *color)
{
	t_vec3	tmp;

	tmp = *color;
	color->x = fmin(255, fmax(0, ((tmp.x * 0.393) + (tmp.y * 0.769) + \
		(tmp.z * 0.189)) + 15));
	color->y = fmin(255, fmax(0, ((tmp.x * 0.349) + (tmp.y * 0.686) + \
		(tmp.z * 0.168)) + 5));
	color->z = fmin(255, fmax(0, ((tmp.x * 0.272) + (tmp.y * 0.534) + \
		(tmp.z * 0.131)) - 5));
}

void				negatif(t_vec3 *color)
{
	color->x = 255 - color->x;
	color->y = 255 - color->y;
	color->z = 255 - color->z;
}

void				black_n_white(t_vec3 *color)
{
	color->x = (color->z + color->y + color->z) / 3;
	color->y = color->x;
	color->z = color->x;
}
