/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    rt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:40:56 by mkrakows          #+#    #+#             */
/*   Updated: 2018/03/30 17:59:30 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int					ft_keyhook(int key, t_control *e)
{
	if (key == K_ESC)
	{
		mlx_destroy_image(e->coef->mlx, e->coef->img);
		free(e->coef);
		free(e->obj);
		free(e->l);
		exit(EXIT_SUCCESS);
	}
	if (key == K_W)
		rename_win(e);
	if (ft_key_aa(key, e))
		multithread(e);
	if (ft_key_camtrans(key, e))
		multithread(e);
	if (ft_key_camrot(key, e))
		multithread(e);
	ft_putnbr(key);
	ft_putendl("");
	return (0);
}

int		ft_key_aa(int key, t_control *e)
{
	if (key == K_O)
	{
		if (e->aliasing == 1)
			e->aliasing = 4;
		else
			e->aliasing = 1;
	}
	else if (key == K_P)
	{
		if (e->antial == 1)
			e->antial = 4;
		else
			e->antial = 1;
	}
	else
		return (0);
	return (1);
}

int		ft_key_camrot(int key, t_control *e)
{
	if (key == K_A)
		e->coef->rot_z += 5;
	else if (key == K_E)
		e->coef->rot_z -= 5;
	else if (key == K_D)
		e->coef->rot_x += 50;
	else if (key == K_Q)
		e->coef->rot_x -= 50;
	else if (key == K_Z)
		e->coef->rot_y += 50;
	else if (key == K_S)
		e->coef->rot_y -= 50;
	else
		return (0);
	return (1);
}

int		ft_key_camtrans(int key, t_control *e)
{
	if (key == K_AU)
		e->coef->pos_x -= 10;
	else if (key == K_AD)
		e->coef->pos_x += 10;
	else if (key == K_RSHIF)
		e->coef->pos_z -= 10;
	else if (key == K_RCTRL)
		e->coef->pos_z += 10;
	else if (key == K_AL)
		e->coef->pos_y -= 10;
	else if (key == K_AR)
		e->coef->pos_y += 10;
	else
		return (0);
	return (1);
}
