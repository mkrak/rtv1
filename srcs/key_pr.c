/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:56:32 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 14:56:33 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		main_loop(t_control *e)
{
	int		test;

	test = 0;
	if (ft_key_camtrans(e) || ft_key_camrot(e) || ft_key_aa(e))
	{
		multithread(e);
		trace_info(e);
	}
	return (1);
}

int		key_r_2(int k, t_control *e)
{
	if (k == K_S)
		e->rotd = 0;
	if (k == K_AU)
		e->au = 0;
	if (k == K_AD)
		e->ad = 0;
	if (k == K_AL)
		e->al = 0;
	if (k == K_AR)
		e->ar = 0;
	if (k == K_RCTRL)
		e->ctrl = 0;
	if (k == K_RSHIF)
		e->shif = 0;
	return (k);
}

int		key_r(int k, t_control *e)
{
	if (k == KP_SUB)
		e->kalisub = 0;
	if (k == KP_ADD)
		e->kaliadd = 0;
	if (k == K_P)
		e->kaa = 0;
	if ((!OS && k == K_A) || (OS && k == K_Q))
		e->roll = 0;
	if (k == K_E)
		e->rolr = 0;
	if (k == K_D)
		e->rotr = 0;
	if ((!OS && k == K_Q) || (OS && k == K_A))
		e->rotl = 0;
	if ((!OS && k == K_Z) || (OS && k == K_W))
		e->rotu = 0;
	return (key_r_2(k, e));
}
