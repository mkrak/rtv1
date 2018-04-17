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

t_point		rotate_cam(t_point d, double x, double y, double z)
{
	t_point tmp;

	tmp = rot_z(rot_y(rot_x(d, x), y), z);
 
	return (tmp);
}

t_point		rot_x(t_point d, double x)
{
	t_point tmp;

	x *= M_PI / 180;
	tmp.posx = d.posx;
	tmp.posy = cos(x) * d.posy - sin(x) * d.posz;
	tmp.posz = sin(x) * d.posy + cos(x) * d.posz;
	
	return (tmp);
}

t_point		rot_y(t_point d, double y)
{
	t_point tmp;

	y *= M_PI / 180;
	tmp.posx = cos(y) * d.posx + sin(y) * d.posz;
	tmp.posy = d.posy;
	tmp.posz = -sin(y) * d.posx + cos(y) * d.posz;
	
	return (tmp);
}

t_point		rot_z(t_point d, double z)
{
	t_point tmp;

	z *= M_PI / 180;
	tmp.posx = cos(z) * d.posx - sin(z) * d.posy;
	tmp.posy = sin(z) * d.posx + cos(z) * d.posy;
	tmp.posz = d.posz;
	
	return (tmp);
}

double		dot(t_point p, t_point b)
{
	return (p.posx * b.posx + p.posy * b.posy + p.posz * b.posz);
}

t_point		moy_point(t_point *moy, int antial)
{
	t_point ret;

	if (antial == 4)
		{
		ret.posx = (moy[0].posx + moy[1].posx + moy[2].posx + moy[3].posx) / antial;
		ret.posy = (moy[0].posy + moy[1].posy + moy[2].posy + moy[3].posy) / antial;
		ret.posz = (moy[0].posz + moy[1].posz + moy[2].posz + moy[3].posz) / antial;
		}
	else
		{
		ret.posx = (moy[0].posx) / antial;
		ret.posy = (moy[0].posy) / antial;
		ret.posz = (moy[0].posz) / antial;
		}
	return (ret); 
}
