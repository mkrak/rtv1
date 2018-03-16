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

t_point		rotate_cam(t_point d, double angle)
{
	t_point tmp;

	angle =  0 * M_PI / 180;
	tmp.posx = d.posx;
	tmp.posy = cos(angle) * d.posy - sin(angle) * d.posz;
	tmp.posz = sin(angle) * d.posy + cos(angle) * d.posz;

	tmp.posx = cos(angle) * d.posx + sin(angle) * d.posz;
	tmp.posy = d.posy;
	tmp.posz = -sin(angle) * d.posx + cos(angle) * d.posz;

	tmp.posx = cos(angle) * d.posx - sin(angle) * d.posy;
	tmp.posy = sin(angle) * d.posx + cos(angle) * d.posy;
	tmp.posz = d.posz;

	return (tmp);
}

double		dot(t_point p, t_point b)
{
	return (p.posx * b.posx + p.posy * b.posy + p.posz * b.posz);
}