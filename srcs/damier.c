/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2018/04/30 13:52:02 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	init_dam(t_control *l, t_inter inter, t_damier *a)
{
	a->px = inter.pos.x - l->obj[inter.id].attr.pos.x;
	a->py = inter.pos.y - l->obj[inter.id].attr.pos.y;
	a->pz = inter.pos.z - l->obj[inter.id].attr.pos.z;
	a->x1 = (int)(floor((a->px / LENGHT_PROCED)));
	a->y1 = (int)(floor((a->py / LENGHT_PROCED)));
	a->z1 = (int)(floor((a->pz / LENGHT_PROCED)));
}

t_vec3	damier(t_control *l, t_inter inter)
{
	t_damier	a;
	t_vec3		color;

	init_dam(l, inter, &a);
	if (a.x1 % 2 == 0)
	{
		if (((a.y1 % 2 == 0) && (a.z1 % 2 == 0)) || \
			(((a.y1 % 2 != 0) && (a.z1 % 2 != 0))))
			color = vec3(0, 0, 0);
		else
			color = vec3(255, 255, 0);
	}
	else
	{
		if (((a.y1 % 2 == 0) && (a.z1 % 2 == 0)) || \
			(((a.y1 % 2 != 0) && (a.z1 % 2 != 0))))
			color = vec3(255, 255, 0);
		else
			color = vec3(0, 0, 0);
	}
	return (color);
}
