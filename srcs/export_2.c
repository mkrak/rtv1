/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:39:03 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 15:39:12 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	hook_mac_rename(t_control *l, int k)
{
	if (k == K_A)
		expand_name(l, 'a');
	else if (k == K_B)
		expand_name(l, 'b');
	else if (k == K_C)
		expand_name(l, 'c');
	else if (k == K_D)
		expand_name(l, 'd');
	else if (k == K_E)
		expand_name(l, 'e');
	else if (k == K_F)
		expand_name(l, 'f');
	else if (k == K_G)
		expand_name(l, 'g');
	else if (k == K_H)
		expand_name(l, 'h');
	else if (k == K_I)
		expand_name(l, 'i');
	else if (k == K_J)
		expand_name(l, 'j');
	else if (k == K_K)
		expand_name(l, 'k');
	else
		hook_mac_rename2(l, k);
}

void	hook_mac_rename2(t_control *l, int k)
{
	if (k == K_L)
		expand_name(l, 'l');
	else if (k == K_M)
		expand_name(l, 'm');
	else if (k == K_N)
		expand_name(l, 'n');
	else if (k == K_O)
		expand_name(l, 'o');
	else if (k == K_P)
		expand_name(l, 'p');
	else if (k == K_Q)
		expand_name(l, 'q');
	else if (k == K_R)
		expand_name(l, 'r');
	else if (k == K_S)
		expand_name(l, 's');
	else if (k == K_T)
		expand_name(l, 't');
	else if (k == K_U)
		expand_name(l, 'u');
	else if (k == K_V)
		expand_name(l, 'v');
	else
		hook_mac_rename3(l, k);
}

void	hook_mac_rename3(t_control *l, int k)
{
	if (k == K_W)
		expand_name(l, 'w');
	else if (k == K_X)
		expand_name(l, 'x');
	else if (k == K_Y)
		expand_name(l, 'y');
	else if (k == K_Z)
		expand_name(l, 'z');
	else if (k == 51)
		trunc_name(l);
}
