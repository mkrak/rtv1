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
	if (key == 65307)
	{
		mlx_destroy_image(e->coef->mlx, e->coef->img);
		free(e->coef);
		free(e->obj);
		free(e->l);
		exit(EXIT_SUCCESS);

	}
	if (key == 119)
		rename_win(e);
///	if (key == 2) //droite
	if (key == 111) //antial (O)
	{
		if (e->aliasing == 1)
			e->aliasing = 4;
		else
			e->aliasing = 1;
	}
	if (key == 112) //alisaing (P)
	{
		if (e->antial == 1)
			e->antial = 4;
		else
			e->antial = 1;
	}
	if (key == 97) //droite
		e->coef->rot_z += 5;
//	if (key == 0) //gauche
	if (key == 101) //gauche
		e->coef->rot_z -= 5;
//	if (key == 2) //droite
	if (key == 100) //droite
		e->coef->rot_x += 50;
//	if (key == 0) //gauche
	if (key == 113) //gauche
		e->coef->rot_x -= 50;
//	if (key == 13) //haut
	if (key == 122) //haut
		e->coef->rot_y += 50;
//	if (key == 1) //bas
	if (key == 115) //bas
		e->coef->rot_y -= 50;
//	if (key == 126) //avant
	if (key == 65362) //avant
		e->coef->pos_x -= 10;
//	if (key == 125) //arriere
	if (key == 65364) //arriere
		e->coef->pos_x += 10;
///	if (key == 123) //gauche
	if (key == 65508) //monter
		e->coef->pos_z -= 10;
//	if (key == 124) //droite
	if (key == 65506) //descendre
		e->coef->pos_z += 10;
//	if (key == 123) //gauche
	if (key == 65361) //gauche
		e->coef->pos_y -= 10;
//	if (key == 124) //droite
	if (key == 65363) //droite
		e->coef->pos_y += 10;
	multithread(*e);
//	else
//		init_w(e);
//		return (0);
	ft_putnbr(key);
	ft_putendl("");
	return (0);
}
