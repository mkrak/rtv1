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


t_point			damier(t_control *l, t_inter inter)
{
    t_damier	a;
    t_point color = init_point(0, 0, 0);

    a.px = inter.pos.posx - l->obj[inter.id].s.p.posx;
    a.py = inter.pos.posy - l->obj[inter.id].s.p.posy;
    a.pz = inter.pos.posz - l->obj[inter.id].s.p.posz;
	a.x1 = (int)(floor((a.px / LENGHT_PROCED)));
	a.y1 = (int)(floor((a.py / LENGHT_PROCED)));
	a.z1 = (int)(floor((a.pz / LENGHT_PROCED)));

    if (a.x1 % 2 == 0)
    {
        if(((a.y1 % 2 == 0) && (a.z1 % 2 == 0)) || (((a.y1 % 2 != 0) && (a.z1 % 2 != 0))))
        {
            color.posx = 0;
            color.posy = 0;
            color.posz = 0;
        }
        else
        {
            color.posx = 255;
            color.posy = 255;
            color.posz = 0;
        }
    }
    else
    {
		if (((a.y1 % 2 == 0) && (a.z1 % 2 == 0)) || (((a.y1 % 2 != 0) && (a.z1 % 2 != 0))))
		{
		    color.posx = 255;
            color.posy = 255;
            color.posz = 0;
		}
		else
		{
            color.posx = 0;
            color.posy = 0;
            color.posz = 0;
		}
    }
    return (color);
}
