/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    rt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:40:56 by mkrakows          #+#    #+#             */
/*   Updated: 2018/03/14 16:19:36 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int					ft_keyhook(int key, t_control *e)
{
	if (key == 53)
	{
		mlx_destroy_image(e->coef->mlx, e->coef->img);
		free(e->coef);
		free(e->r);
		free(e->obj);
		free(e->l);
		exit(EXIT_SUCCESS);

	}
	if (key == 14 || key == 101)
		rename_win(e);
//	else
//		init_w(e);
//		return (0);
	ft_putnbr(key);
	ft_putendl("");
	return (0);
}
