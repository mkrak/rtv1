/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:02:52 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 14:05:37 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	trace_info(t_control *c)
{
	if (c->coef->menu_state == 0)
		trace_info_0(c);
	if (c->coef->menu_state == 1)
		trace_info_1(c);
	if (c->coef->menu_state == 2)
		trace_info_2(c);
}

int		ft_key_aa(t_control *e)
{
	if (e->kalisub)
	{
		if (e->aliasing > 1)
			e->aliasing -= 1;
		else
		{
			e->aliasing = 1;
			return (0);
		}
	}
	else if (e->kaliadd)
		e->aliasing += 1;
	else if (e->kaa)
	{
		if (e->antial == 1)
			e->antial *= 4;
		else
			e->antial = 1;
	}
	else
		return (0);
	return (1);
}

int		ft_key_camrot(t_control *e)
{
	if (e->roll)
		e->coef->rot_z += 5;
	else if (e->rolr)
		e->coef->rot_z -= 5;
	else if (e->rotr)
		e->coef->rot_x -= 5;
	else if (e->rotl)
		e->coef->rot_x += 5;
	else if (e->rotu)
		e->coef->rot_y += 5;
	else if (e->rotd)
		e->coef->rot_y -= 5;
	else
		return (0);
	return (1);
}

int		ft_key_camtrans(t_control *e)
{
	if (e->au)
		e->coef->pos_x -= 1;
	if (e->ad)
		e->coef->pos_x += 1;
	if (e->ctrl)
		e->coef->pos_z -= 1;
	if (e->shif)
		e->coef->pos_z += 1;
	if (e->al)
		e->coef->pos_y -= 1;
	if (e->ar)
		e->coef->pos_y += 1;
	if (!e->au && !e->ad && !e->ctrl && !e->shif && !e->al && !e->ar)
		return (0);
	return (1);
}
